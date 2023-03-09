#pragma once

#include "TestCudaPower2.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestReductionGenericLongII: public TestCudaPower2
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TestReductionGenericLongII();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    protected:

	/**
	 * Override
	 */
	void allTests();

    private:

	void testspecialGridDGXMAX();

	void testSpecialGrid2();

	void testSpecialeMax();

	void testSpecialPerformance();

	static long thresholdPerformanceFps();


	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:



    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

