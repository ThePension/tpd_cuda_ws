#pragma once

#include "Provider_uchar4_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class RaytracingProviderCM2SM: public Provider_uchar4_A
    {
    public:

	/**
	 * Override
	 */
	virtual Grid grid();

	/**
	 * Override
	 */
	virtual Animable_I<uchar4>* createAnimable(const Grid& grid , bool isVerbose = false);


    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

