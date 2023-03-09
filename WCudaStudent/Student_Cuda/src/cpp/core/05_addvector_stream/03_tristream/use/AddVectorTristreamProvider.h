#pragma once

#include "ProviderUse_I.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class AddVectorTristreamProvider: public ProviderUse_I
    {

	/*------------------------------------------------------------*\
	 |*			Constructeur 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * nbSlice in [3,12]
	 */
	AddVectorTristreamProvider(int nbSlice);

	virtual ~AddVectorTristreamProvider();

	/*------------------------------------------------------------*\
        |*			Methodes 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * override
	 * Mandatory : delete yourself UseGPU_I*
	 * nbSlice in [3,12]
	 */
	Use_I* createUse(const Grid& grid , bool isVerbose = false);

	/**
	 * override
	 * Mandatory : delete yourself UseGPU_I*
	 * nbSlice in [3,12]
	 */
	Use_I* createUse( bool isVerbose = true);

	/*------------------------------------------------------------*\
	|*			Methodes 			      *|
	 \*------------------------------------------------------------*/

    private:

	// Inputs
	int nbSlice;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
