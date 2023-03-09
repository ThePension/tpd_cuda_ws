#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"
#include "Maths.h"

#include "Calibreur.cu.h"
#include "Indices.cu.h"
#include "ifelse.cu.h"
#include "Edge.cu.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * text2d 	: read
 * tabPixelGM   : write
 *
 * Note: fait par exemple disparaitre les points noirs dans les bandes blanches de la route (pour video autoroute)
 */
__global__ void KDilatation1(uchar* tabPixelGM , cudaSurfaceObject_t surf2d , uint w , uint h)
    {
    // 1) Parcourir tous les pixels, y compris ceux du bord
    // 2) Voir si un pixel voisin est a 255, si oui on devient aussi a 255
    //
    // Truc   : grace a la surface pas besoin de gerer les bords de l'image de maniere specifique
    //
    // Rappel 1:  uchar pixels;
    //		 surf2Dread(&pixelS, surf2d, j, i);
    //
    // Rappel 2:
    //		uchar pixels= surf2Dread<uchar>(surf2d, j, i);
    //
    // Warning : (j,i) et non (i,j)

    // TODO KDilatation1

    }

/**
 * Amelioration:
 * 	on pourrait prendre un voisinage v8 avec une (ou plusieurs) aurole de plus, autour du pixels,
 *	pour faire disparaitre encore plus de zone noir dans la bande blanche, quitte a fire une errosion apres
 *	Voir KDilatationN ci-dessous
 */
__global__ void KDilatationN(uchar* tabPixelGM , cudaSurfaceObject_t surf2d , uint w , uint h , int rayon)
    {
    // bonus
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

