#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"

#include "Indices.cu.h"

#include "RipplingMath.cu.h"


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

__global__ void rippling(uchar4* tabPixelsGM , uint w , uint h , float t)
    {
    // TODO instacier RipplingMath

    const int TID = Thread2D::tid();
    const int NB_THREAD = Thread2D::nbThread();
    const int WH = w * h;

    // TODO Rippling GPU  pattern entrelacement
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

