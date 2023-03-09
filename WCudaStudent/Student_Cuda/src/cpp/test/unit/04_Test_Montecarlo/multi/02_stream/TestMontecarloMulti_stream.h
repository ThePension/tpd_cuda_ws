#pragma once

#include "TestCudaPower2.h"
#include "FilterGridMontecarlo.h"
#include "MontecarloUseTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestMontecarloMulti_stream: public TestCudaPower2
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TestMontecarloMulti_stream(float h=MontecarloUseTools::H);

	~TestMontecarloMulti_stream();

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

	FilterGridMontecarlo* ptrFilterGridMontecarlo;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

