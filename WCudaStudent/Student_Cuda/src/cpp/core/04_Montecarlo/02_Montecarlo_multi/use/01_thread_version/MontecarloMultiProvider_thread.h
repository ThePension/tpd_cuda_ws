#pragma once

#include "ProviderUse_I.h"
#include "entier.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class MontecarloMultiProvider_thread: public ProviderUse_I
    {


	/*------------------------------------------------------------*\
	 |*			Constructeur 			      *|
	 \*------------------------------------------------------------*/

    public:

	MontecarloMultiProvider_thread();

	MontecarloMultiProvider_thread(float h , entier nbDar);

	virtual ~MontecarloMultiProvider_thread();


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
