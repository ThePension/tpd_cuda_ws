#include "ReductionIntI.h"

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

extern __global__ void KIntProtocoleI(int* ptrSumGM);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

ReductionIntI::ReductionIntI(const Grid& grid , int* ptrSum,bool isVerbose) :
	RunnableGPU(grid, "ReductionIntI-" + to_string(grid.threadCounts()),isVerbose), // classe parente
	ptrSum(ptrSum)
    {
    // TODO ReductionIntI
    this->sizeSM = -1;
    }

ReductionIntI::~ReductionIntI()
    {
    // TODO ReductionIntI
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void ReductionIntI::run()
    {
    // TODO ReductionIntI
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
