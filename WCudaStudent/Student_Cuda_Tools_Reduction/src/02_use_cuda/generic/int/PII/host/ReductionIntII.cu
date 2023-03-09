#include "ReductionIntII.h"

#include "GM.h"
#include "Grid.h"

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void KIntProtocoleII(int* ptrSumGM);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

ReductionIntII::ReductionIntII(const Grid& grid , int* ptrSum,bool isVerbose) :
	RunnableGPU(grid, "ReductionIntII-" + to_string(grid.threadCounts()),isVerbose), // classe parente
	ptrSum(ptrSum)
    {
    // TODO ReductionIntII
    this->sizeSM = -1;
    }

ReductionIntII::~ReductionIntII()
    {
    // TODO ReductionIntII
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void ReductionIntII::run()
    {
    // TODO ReductionIntII
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
