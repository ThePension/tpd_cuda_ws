#include "TestMontecarloMulti_stream.h"

#include "ChronoFactory.h"
#include "Limits.h"
#include "Maths.h"

#include "FilterGridMontecarlo.h"
#include "MontecarloMultiProvider_stream.h"
#include "MontecarloUseTools.h"
#include "entier.h"

#include <iostream>
#include <assert.h>

using std::cerr;
using std::cout;
using std::endl;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestMontecarloMulti_stream::TestMontecarloMulti_stream(float h) : //
	TestCudaPower2(new MontecarloMultiProvider_stream(h,MontecarloUseTools::nbDarTotalTest()))
    {
    enableTestPerformance(true, thresholdPerformanceFps());

    this->ptrFilterGridMontecarlo = new FilterGridMontecarlo();
    addFilter(ptrFilterGridMontecarlo);
    }

TestMontecarloMulti_stream::~TestMontecarloMulti_stream()
    {
    delete ptrFilterGridMontecarlo;
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestMontecarloMulti_stream::allTests()
    {
    TestCudaPower2::allTests();

    TEST_ADD(TestMontecarloMulti_stream::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestMontecarloMulti_stream::testSpecial()
    {
    showTitle("Test special ");

    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    dim3 dg(MP, 1, 1);
    dim3 db(1024, 1, 1); //power 2
    Grid grid(dg, db);

    test(grid);
    }

/**
 * static
 */
long TestMontecarloMulti_stream::thresholdPerformanceFps()
    {
#ifdef DAR_INT
    return 450; // cbi naif 571
#endif

#ifdef DAR_LONG
    return 100; // cbi 143
        #endif

    assert(false);// ne doit jamais arriver
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

