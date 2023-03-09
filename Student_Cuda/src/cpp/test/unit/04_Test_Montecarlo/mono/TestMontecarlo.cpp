#include "TestMontecarlo.h"

#include "ChronoFactory.h"
#include "Limits.h"
#include "Maths.h"

#include "FilterGridMontecarlo.h"
#include "MontecarloProvider.h"
#include "MontecarloUseTools.h"
#include "entier.h"

#include <iostream>
#include <assert.h>

using std::cout;
using std::cerr;
using std::endl;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestMontecarlo::TestMontecarlo(float h) : //
	TestCudaPower2(new MontecarloProvider(h,MontecarloUseTools::nbDarTotalTest()))
    {
    enableTestPerformance(true, thresholdPerformanceFps());

    this->ptrFilterGridMontecarlo = new FilterGridMontecarlo();
    addFilter(ptrFilterGridMontecarlo);
    }

TestMontecarlo::~TestMontecarlo()
    {
    delete ptrFilterGridMontecarlo;
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestMontecarlo::allTests()
    {
    TestCudaPower2::allTests();

    TEST_ADD(TestMontecarlo::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestMontecarlo::testSpecial()
    {
    showTitle("Test special ");

    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    dim3 dg(MP, 1, 1);
    dim3 db(1024, 1, 1); //power 2
    Grid grid(dg, db);

    test(grid);
    }

/*--------------------------------------*\
 |*		private		*|
 \*-------------------------------------*/

/**
 * static
 */
long TestMontecarlo::thresholdPerformanceFps()
    {
    #ifdef DAR_INT
	return 160; // cbi naif 200
    #endif

    #ifdef DAR_LONG
	return 35; // cbi naif 46
    #endif

    assert(false); // ne doit jamais arriver
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

