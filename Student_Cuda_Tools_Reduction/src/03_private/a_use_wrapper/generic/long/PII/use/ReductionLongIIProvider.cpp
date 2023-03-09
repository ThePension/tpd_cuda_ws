#include "ReductionLongIIProvider.h"

#include "UseReductionLongII.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionLongIIProvider::createUse(const Grid& grid,bool isVerbose)
    {
    return new UseReductionLongII(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionLongIIProvider::createUse(bool isVerbose)
    {
    return new UseReductionLongII(isVerbose);
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
