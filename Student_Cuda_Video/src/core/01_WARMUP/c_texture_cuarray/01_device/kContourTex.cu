#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"
#include "Maths.h"

#include "Indices.cu.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * <pre>
 * source : 	tex2dVideo
 * destination :tabPixelsGM
 * </pre>
 */
__global__ void kContourTex(cudaTextureObject_t tex2dVideo , uchar* tabPixelsGM , uint w , uint h)
    {
    // on lit dans tex2dVideo
    // Youpie : 	Pas besoin de gerer les bords car on a une texture
    // Rappel :		uchar pixels = tex2D < uchar > (tex2dVideo, j,i);
    // warning: 	tex2D(j,i) et non tex2D(i,j)

    // TODO kContourTex
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

