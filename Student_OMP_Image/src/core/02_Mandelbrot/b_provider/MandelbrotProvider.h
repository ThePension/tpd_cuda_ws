#pragma once

#include "Animable_I_CPU.h"
#include "Provider_I_CPU.h"

using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class MandelbrotProvider: public Provider_I<uchar4>
    {
    public:

	/**
	 * Override
	 */
	Animable_I<uchar4>* createAnimable(void);

	/**
	 * Override
	 */
	Image_I* createImageGL(void);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

