#pragma once

#include "entier.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * mono et multiGPU
 */
class MontecarloUseTools
    {

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	static entier nbDarTotalUse();

	static entier nbDarTotalTest();

	static void performance(double timeS , entier nbDar , bool isOk);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    public:

 	static const float H ;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
