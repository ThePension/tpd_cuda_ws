#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "ReductionAdd.cu.h"

#include "cudas.h"

#include <stdio.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __device__ void reductionIntraThread(float* tabSM,int nbSlice);
static __device__ float f(float x);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

__global__ void sliceSM(int nbSlice , float* ptrPiHatGM)
    {
    // TODO SliceSM

    // Declarer tabSM
    // ReductionIntraThread
    // Reduction de tabSM (use tools ReductionAdd)

    // __syncthreads(); necessaire? ou?
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * remplit la sm
 */
__device__ void reductionIntraThread(float* tabSM , int nbSlice)
    {
    // TODO SliceSM

    // Warning: Il faut employer TID et TID_LOCAL
    }

__device__ float f(float x)
    {
    // TODO SliceSM
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

