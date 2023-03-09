#include "AddVectorTristreamProvider.h"

#include "AddVectorTristreamUse.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

AddVectorTristreamProvider::AddVectorTristreamProvider(int nbSlice) : //
	nbSlice(nbSlice)
    {
    // rien
    }

AddVectorTristreamProvider::~AddVectorTristreamProvider()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode		*|
 \*-------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* AddVectorTristreamProvider::createUse(const Grid& grid , bool isVerbose)
    {
    return new AddVectorTristreamUse(grid, nbSlice, isVerbose);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* AddVectorTristreamProvider::createUse(bool isVerbose)
    {
    return new AddVectorTristreamUse(nbSlice, isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
