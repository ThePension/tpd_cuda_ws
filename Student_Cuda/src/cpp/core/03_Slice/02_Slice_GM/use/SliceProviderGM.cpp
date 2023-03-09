#include "SliceProviderGM.h"

#include "SliceGmUse.h"



/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* SliceProviderGM::createUse(const Grid& grid,bool isVerbose)
    {
    return new SliceGmUse(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* SliceProviderGM::createUse(bool isVerbose)
    {
    return new SliceGmUse(isVerbose);
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
