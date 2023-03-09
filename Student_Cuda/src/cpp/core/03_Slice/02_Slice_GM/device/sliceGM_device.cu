#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"

#include <stdio.h>

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
 * puis stocke son résultat dans SA case dans tabGM
 *
 * tabGM est un tableau promu, qui a autant de case que de thread
 * </pre>
 */
__global__ void reductionIntraThreadGM(float* tabGM , int nbSlice)
    {
   // TODO SliceGM (idem SliceGMHOST) pour cette partie
    }

/**
 * <pre>
 * Effectue la reduction de tabGM cote device, par ecrasement 2 à 2 successif.
 * Ce kernel d ecrasement est appeler depuis le host dans une boucle, avec le bon nombre de thread
 *
 * Hypothese : |tabGM| est une puissance de 2
 *
 * Output: le resultat de la reduction est tans tabGM[0]
 * </pre>
 */
__global__ void ecrasementGM(float* tabGM , int middle)
    {
    // TODO SliceGM
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__device__ float f(float x)
    {
    // TODO SliceGM
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

