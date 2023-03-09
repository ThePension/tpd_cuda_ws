#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"
#include "Maths.h"

#include "Calibreur.cu.h"
#include "Indices.cu.h"
#include "ifelse.cu.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/
/**
 * tabPixelGM   : read
 * surf2dGM     : write
 */
__global__ void kSeuillage(cudaSurfaceObject_t surf2d , uchar* tabPixelGM , uint w , uint h , uchar seuil0255)
    {
    // 1) Chaque pixel devient 1 ou 255 selon si il est plus petit ou plus grand que le seuil0255
    // 2) Pour evitre la thread divergence avec un "if else standard", utiliser la methode "ifelse" de ifelse.cu.h
    //    Aller surtout regarder son implementation (f3 dans le include ci-dessus)
    //
    // Rappel : surf2Dwrite(pixelS, surf2d, j, i);  (j,i) et non (i,j)

    // TODO kSeuillage
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

