#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"

#include <stdio.h>

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * output : void required, car kernel is asynchrone
 * pattern entrelacement
 */
__global__ void addArray(float* ptrDevV1 , float* ptrDevV2 , float* ptrDevW , int n)
    {
    const int NB_THREAD = Thread2D::nbThread();
    const int TID = Thread2D::tid();

    // Debug, facultatif
//    if (TID == 0)
//	{
//	printf("Coucou from device tid = %d", TID);
//	}

    // TODO addArray
    // Je suis un chinois, qu'est-ce que je dois faire ?
    int s = TID;

    while(s < n)
	{
	ptrDevW[s] += ptrDevV1[s] + ptrDevV2[s];
	s += NB_THREAD;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

