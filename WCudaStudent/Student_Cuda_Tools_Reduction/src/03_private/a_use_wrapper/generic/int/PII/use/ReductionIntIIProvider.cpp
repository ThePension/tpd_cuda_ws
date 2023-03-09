#include "ReductionIntIIProvider.h"

#include "UseReductionIntII.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionIntIIProvider::createUse(const Grid& grid,bool isVerbose)
    {
    return new UseReductionIntII(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionIntIIProvider::createUse(bool isVerbose)
    {
    return new UseReductionIntII(isVerbose);
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
