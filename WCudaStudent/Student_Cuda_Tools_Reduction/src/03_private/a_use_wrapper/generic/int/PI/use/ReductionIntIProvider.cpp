#include "ReductionIntIProvider.h"

#include "UseReductionIntI.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionIntIProvider::createUse(const Grid& grid,bool isVerbose)
    {
    return new UseReductionIntI(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionIntIProvider::createUse(bool isVerbose)
    {
    return new UseReductionIntI(isVerbose);
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
