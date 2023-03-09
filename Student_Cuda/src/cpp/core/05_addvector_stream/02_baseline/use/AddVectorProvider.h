#pragma once

#include "ProviderUse_I.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class AddVectorProvider: public ProviderUse_I
    {

	/*------------------------------------------------------------*\
        |*			Methodes 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * override
	 * Mandatory : delete yourself UseGPU_I*
	 */
	Use_I* createUse(const Grid& grid,bool isVerbose=false);

	/**
	 * override
	 * Mandatory : delete yourself UseGPU_I*
	 */
	Use_I* createUse(bool isVerbose=true);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
