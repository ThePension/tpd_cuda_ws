#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"

#include <stdio.h>

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * <pre>
 * Output :
 *
 * 		void required, car kernel is asynchrone!
 *
 * Contrainte:
 * 		pattern 1<-->1
 * 		On associe un thread a chaque case du tableau
 * </pre>
 */
__global__ void addArray11(float* ptrDevV1 , float* ptrDevV2 , float* ptrDevW , int n)
    {
    const int TID = Thread2D::tid();

    // TODO addArray11
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

