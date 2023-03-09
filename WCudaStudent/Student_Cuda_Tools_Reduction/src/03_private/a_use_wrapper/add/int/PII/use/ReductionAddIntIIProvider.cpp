#include "ReductionAddIntIIProvider.h"

#include "UseReductionAddIntII.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionAddIntIIProvider::createUse(const Grid& grid,bool isVerbose)
    {
    return new UseReductionAddIntII(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionAddIntIIProvider::createUse(bool isVerbose)
    {
    return new UseReductionAddIntII(isVerbose);
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
