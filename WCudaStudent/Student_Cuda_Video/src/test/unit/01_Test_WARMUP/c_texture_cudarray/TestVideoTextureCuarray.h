#pragma once

#include "TestCuda.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestVideoTextureCuarray: public TestCuda
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TestVideoTextureCuarray();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    protected:

	/**
	 * Override
	 */
	void allTests();

    private:

	void testSpecial();

	static long thresholdPerformanceFps();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:


    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

