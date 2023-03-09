#include "SliceProviderGMHOST.h"

#include "SliceGmHostUse.h"



/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* SliceProviderGMHOST::createUse(const Grid& grid,bool isVerbose)
    {
    return new SliceGmHostUse(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* SliceProviderGMHOST::createUse(bool isVerbose)
    {
    return new SliceGmHostUse(isVerbose);
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
