#include "TestMontecarloMulti_thread.h"

#include "ChronoFactory.h"
#include "Limits.h"
#include "Maths.h"

#include "FilterGridMontecarlo.h"
#include "MontecarloMultiProvider_thread.h"
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

TestMontecarloMulti_thread::TestMontecarloMulti_thread(float h) : //
	TestCudaPower2(new MontecarloMultiProvider_thread(h,MontecarloUseTools::nbDarTotalTest()))
    {
    enableTestPerformance(true, thresholdPerformanceFps());

    this->ptrFilterGridMontecarlo = new FilterGridMontecarlo();
    addFilter(ptrFilterGridMontecarlo);
    }

TestMontecarloMulti_thread::~TestMontecarloMulti_thread()
    {
    delete ptrFilterGridMontecarlo;
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestMontecarloMulti_thread::allTests()
    {
    TestCudaPower2::allTests();

    TEST_ADD(TestMontecarloMulti_thread::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestMontecarloMulti_thread::testSpecial()
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
long TestMontecarloMulti_thread::thresholdPerformanceFps()
    {
#ifdef DAR_INT
    return 85; // cbi naif 106, tout dans run y compris instanciation
   // return 260; // cbi instanciation dans cc
#endif

#ifdef DAR_LONG
	return 40; // cbi 58
	//return 80; // cbi instanciation dans cc
        #endif

    assert(false);// ne doit jamais arriver
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

