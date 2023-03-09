#include "cudas.h"

#include <stdio.h>


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * Hyp : 1 seul thread, ie dg(1,1,1) et db (1,1,1)
 */
__global__ void addScalar(float a , float b , float* ptrSumGM)
    {
    *ptrSumGM = a + b;

    // debug (1 seule thread ici)
    printf("\n[Hello : Device side : addScalar object] %.0f + %.0f = %.0f", a, b, *ptrSumGM);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

