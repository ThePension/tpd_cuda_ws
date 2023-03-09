#include "UseReductionLong.h"

#include "Maths.h"
#include "Hardware.h"
#include "Limits.h"

#include <iostream>
#include <iomanip>
#include <assert.h>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::setprecision;

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

UseReductionLong::UseReductionLong(const Grid& grid , bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PLong* ptrPlong) : //
	grid(grid), //
	sum(-1), //
	ptrRunnableGPU(ptrRunnableGPU), //
	ptrPlong(ptrPlong)
    {
    //assert(filter(grid));
    }

UseReductionLong::UseReductionLong(bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PLong* ptrPlong) : //
	UseReductionLong(createGrid(*ptrPlong), isVerbose, ptrRunnableGPU, ptrPlong)
    {
    //rien
    }

UseReductionLong::~UseReductionLong()
    {
    delete ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 */
bool UseReductionLong::filter(const Grid& grid)
    {
    return Use_I::filter(grid) //
    && Maths::isPower2(grid.threadByBlock()) //
	    && grid.blockCounts() <= ptrPlong->dgxMax() //
	    && ptrPlong->isSizeMaxOK(grid);
    }

/*--------------*\
|*	isOk	*|
 \*-------------*/

/**
 * Override
 */
bool UseReductionLong::isOk(bool isVerbose)
    {
    this->ptrRunnableGPU->run();

    long sumExpected = ptrPlong->resultatTheorique(grid);

    bool isOk = (sum == sumExpected);

    if (isVerbose)
	{
	string title = "[" + ptrRunnableGPU->getTitle() + "]";
	cout << setprecision(4);
	cout << endl;
	cout << title << " : sum found    = " << sum << endl;
	cout << title << " : sum expected = " << sumExpected << endl;
	cout << title << " : ";

	if (isOk)
	    {
	    cout << "Success!" << endl;
	    }
	else
	    {
	    cerr << "Failed!" << endl;
	    }
	}
    return isOk;
    }

/*--------------*\
|*	get	*|
 \*-------------*/

/**
 * override
 * Warning : It's a getter, the user is not responsible for deleting RunnableGPU_I*
 */
RunnableGPU_I* UseReductionLong::getRunnableGPU()
    {
    return this->ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/


Grid UseReductionLong::createGrid(const PLong& plong)
    {
    const bool IS_CHECK_HEURISTIC = false;

    const int DBX_MAX = 1024; 		// limite materielle
    const int DGX_MAX = plong.dgxMax();

    dim3 dg(DGX_MAX, 1, 1);
    dim3 db(DBX_MAX, 1, 1);
    Grid grid(dg, db, IS_CHECK_HEURISTIC);

    return grid;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
