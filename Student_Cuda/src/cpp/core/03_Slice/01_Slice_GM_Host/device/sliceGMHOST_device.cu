#include <stdio.h>
#include <Thread2D.cu.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __device__ float f(float x);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * <pre>
 * Chaque thread effecteur une reduction intrathread avec le patern d'entrelacement,
 * puis stocke son resultat dans SA case dans tabGM
 *
 * tabGM est un tableau promu, qui a autant de case que de thread
 * </pre>
 */
__global__ void reductionIntraThreadGMHOST(float* tabGM , int nbSlice)
    {
    const int NB_THREAD = Thread2D::nbThread();
    const int TID = Thread2D::tid();
    const float DX = 1.f / nbSlice;

    int s = TID;
    float sum = 0.f;
    while (s < nbSlice)
	{
	sum += f(s * DX);
	s += NB_THREAD;
	}

    tabGM[TID] = sum;

    // Conseils :
    //
    //		(C1) 	Ne calculer pas en double cote device, mais tout en float.
    //			En particulier, on ecrira 4.0f et non 4 (meme si ici le compilateur va l'optimiser a notre place, mais c'est bien de la faire par principe)
    //
    // 		(C2) 	Effectuez plutot le fois DX de l'aire du slice une seule fois par Thread, que pour chaque slice,
    //          	 ou qu'une seule fois cote host (debordement de type float cote device, car on ne fait que sommer?)
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__device__ float f(float x)
    {
    return 4.f / (1.f + x * x);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

