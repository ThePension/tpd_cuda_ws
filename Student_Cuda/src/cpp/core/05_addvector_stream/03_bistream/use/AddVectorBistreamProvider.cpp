#include "AddVectorBistreamProvider.h"

#include "AddVectorBistreamUse.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* AddVectorBistreamProvider::createUse(const Grid& grid,bool isVerbose)
    {
    return new AddVectorBistreamUse(grid,isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* AddVectorBistreamProvider::createUse(bool isVerbose)
    {
    return new AddVectorBistreamUse(isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
