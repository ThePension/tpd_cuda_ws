#include "AddVectorTristreamUse.h"

#include "VectorTools.h"
#include "AddVectorTristream.h"
#include "Limits.h"

#include "Maths.h"
#include "Hardware.h"

#include <iostream>
#include <iomanip>
#include <assert.h>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::setprecision;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Constructor		*|
 \*-------------------------------------*/

AddVectorTristreamUse::AddVectorTristreamUse(const Grid& grid , int nbSlice , bool isVerbose) : //
	grid(grid), //
	n(VectorTools::n())
    {
    assert(filter(grid));

    this->ptrV1 = VectorTools::createV1(n);
    this->ptrV2 = VectorTools::createV2(n);
    this->ptrW = VectorTools::create(n);

    this->ptrRunnableGPU = new AddVectorTristream(grid, ptrV1, ptrV2, ptrW, n, nbSlice, isVerbose);
    }

AddVectorTristreamUse::AddVectorTristreamUse(int nbSlice , bool isVerbose) : //
	AddVectorTristreamUse(createGrid(), nbSlice, isVerbose)
    {
    //rien
    }

AddVectorTristreamUse::~AddVectorTristreamUse()
    {
    delete ptrRunnableGPU; // warning : si destructeur pas virtuel dans classe parente de AddVector, ko, car appel destructeur super classe only!
    //delete ((AddVector*)ptrRunnableGPU); // plus safe!

    VectorTools::free(ptrV1);
    VectorTools::free(ptrV2);
    VectorTools::free(ptrW);
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 */
bool AddVectorTristreamUse::filter(const Grid& grid)
    {
    return Use_I::filter(grid);
    }

int AddVectorTristreamUse::getN()
    {
    return n;
    }

/*--------------------------------------*\
|*		isOk			*|
 \*-------------------------------------*/

bool AddVectorTristreamUse::isOk(bool isVerbose)
    {
    this->ptrRunnableGPU->run();

    bool isOk = VectorTools::isAddVector_Ok(ptrV1, ptrV2, ptrW, n);

    if (isVerbose)
	{
	VectorTools::print(ptrV1, n);
	VectorTools::print(ptrV2, n);
	cout << "--------------------------------------------------------------------" << endl;
	VectorTools::print(ptrW, n);
	cout << endl;

	cout << "[" << ptrRunnableGPU->getTitle() << "] : ";

	if (isOk)
	    {
	    cout << "Success!" << endl << endl;
	    }
	else
	    {
	    cerr << "Failed!" << endl << endl;
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
RunnableGPU_I* AddVectorTristreamUse::getRunnableGPU()
    {
    return this->ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/

/**
 * static
 *
 * Pour le nombre de slice optimum
 */
Grid AddVectorTristreamUse::createGrid()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    // TODO addVector
    // dim3 dg
    // dim3 db // contrainte : max(db.x*db.y*db.z)<=1024
    Grid grid; // TODO

    assert(false);        // to remove once coded

    return grid;
    }

/**
 * static
 */
int AddVectorTristreamUse::nbSliceOptimum()
    {
    const int N = 3; // TODO
    assert(false);        // to remove once coded

    // check
	{
	assert(N >= 3);
	assert(VectorTools::n() % N == 0);
	}

    return N;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
