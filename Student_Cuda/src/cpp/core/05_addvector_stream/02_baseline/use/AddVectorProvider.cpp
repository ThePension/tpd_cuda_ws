#include "AddVectorProvider.h"

#include "AddVectorUse.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* AddVectorProvider::createUse(const Grid& grid,bool isVerbose)
    {
    return new AddVectorUse(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* AddVectorProvider::createUse(bool isVerbose)
    {
    return new AddVectorUse(isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
