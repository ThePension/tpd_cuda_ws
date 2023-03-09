#include "ReductionAddIntIProvider.h"

#include "UseReductionAddIntI.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionAddIntIProvider::createUse(const Grid& grid,bool isVerbose)
    {
    return new UseReductionAddIntI(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* ReductionAddIntIProvider::createUse(bool isVerbose)
    {
    return new UseReductionAddIntI(isVerbose);
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
