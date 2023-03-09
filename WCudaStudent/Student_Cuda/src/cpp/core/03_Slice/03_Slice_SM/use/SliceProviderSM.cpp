#include "SliceProviderSM.h"

#include "SliceSmUse.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* SliceProviderSM::createUse(const Grid& grid,bool isVerbose)
    {
    return new SliceSmUse(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* SliceProviderSM::createUse(bool isVerbose)
    {
    return new SliceSmUse(isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
