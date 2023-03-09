#pragma once

#include "ProviderUse_I.h"
#include "entier.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class MontecarloMultiProvider_stream: public ProviderUse_I
    {


	/*------------------------------------------------------------*\
	 |*			Constructeur 			      *|
	 \*------------------------------------------------------------*/

    public:

	MontecarloMultiProvider_stream();

	MontecarloMultiProvider_stream(float h , entier nbDar);

	virtual ~MontecarloMultiProvider_stream();


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

	/*------------------------------------------------------------*\
	|*			Methodes 			      *|
	 \*------------------------------------------------------------*/

    private:

	// Inputs
	entier nbDar;
	float h;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
