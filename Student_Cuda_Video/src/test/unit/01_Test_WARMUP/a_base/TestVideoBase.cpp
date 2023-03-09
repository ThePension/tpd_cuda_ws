#include "TestVideoBase.h"

#include "VideoBaseProvider.h"

#include <iostream>
#include <assert.h>

using std::cerr;
using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestVideoBase::TestVideoBase() :
	TestCuda((ProviderUse_I*)new VideoBaseProvider())
    {
    enableTestPerformance(true, thresholdPerformanceFps());
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestVideoBase::allTests()
    {
    TEST_ADD(TestCuda::testPerformance); // @suppress("Invalid overload")
    TEST_ADD(TestVideoBase::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestVideoBase::testSpecial()
    {
    showTitle("Test special ");

    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    const bool IS_CHECK_HEURISTIC = false;
    dim3 dg(64, 1, 1);
    dim3 db(1024, 1, 1);
    Grid grid(dg, db, IS_CHECK_HEURISTIC); // power 2

    test(grid);
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
long TestVideoBase::thresholdPerformanceFps()
    {
    return 4000; // cbi naif  4715
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

