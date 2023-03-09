#pragma once

#include "TestCuda.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestRaytracingSM: public TestCuda
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TestRaytracingSM();

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
