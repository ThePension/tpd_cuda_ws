#include "ReductionLongII.h"

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

extern __global__ void KLongProtocoleII(long* ptrSumGM);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

ReductionLongII::ReductionLongII(const Grid& grid , long* ptrSum,bool isVerbose) :
	RunnableGPU(grid, "ReductionLongII-" + to_string(grid.threadCounts()),isVerbose), // classe parente
	ptrSum(ptrSum)
    {
    // TODO ReductionLongII
    this->sizeSM = -1;
    }

ReductionLongII::~ReductionLongII()
    {
    // TODO ReductionLongII
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void ReductionLongII::run()
    {
    // TODO ReductionLongII
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
