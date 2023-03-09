#include "UseReductionInt.h"

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

UseReductionInt::UseReductionInt(const Grid& grid , bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PInt* ptrPint) : //
	grid(grid), //
	sum(-1), //
	ptrRunnableGPU(ptrRunnableGPU), //
	ptrPint(ptrPint)
    {
    //assert(filter(grid));
    }

UseReductionInt::UseReductionInt(bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PInt* ptrPint) : //
	UseReductionInt(createGrid(*ptrPint), isVerbose, ptrRunnableGPU, ptrPint)
    {
    //rien
    }

UseReductionInt::~UseReductionInt()
    {
    delete ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 */
bool UseReductionInt::filter(const Grid& grid)
    {
    return Use_I::filter(grid) //
    && Maths::isPower2(grid.threadByBlock()) //
	    && grid. blockCounts()<= ptrPint->dgxMax(grid.threadByBlock()) //
	    && ptrPint->isSizeMaxOK(grid);
    }

/*--------------*\
|*	isOk	*|
 \*-------------*/

/**
 * Override
 */
bool UseReductionInt::isOk(bool isVerbose)
    {
    this->ptrRunnableGPU->run();

    int sumExpected = ptrPint->resultatTheorique(grid);

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
RunnableGPU_I* UseReductionInt::getRunnableGPU()
    {
    return this->ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/


Grid UseReductionInt::createGrid(const PInt& pint)
    {
    const bool IS_CHECK_HEURISTIC = false;

    const int DBX_MAX = 1024; 		// limite materielle
    const int DGX_MAX = pint.dgxMax(DBX_MAX);

    dim3 dg(DGX_MAX, 1, 1);
    dim3 db(DBX_MAX, 1, 1);
    Grid grid(dg, db, IS_CHECK_HEURISTIC);

    return grid;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
