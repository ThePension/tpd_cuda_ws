#include "TestSliceGMHOST.h"

#include "Limits.h"
#include "Hardware.h"
#include "Maths.h"
#include "Iterator.h"
#include "SliceNumber.h"
#include "ChronoFactory.h"

#include "SliceProviderGMHOST.h"

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

TestSliceGMHOST::TestSliceGMHOST() :
	TestCuda(new SliceProviderGMHOST())
    {
     enableTestMonoBlock(true);
    enableTestMonoThread(true);
    enableTestPerformance(true, thresholdPerformanceFps());
    }

TestSliceGMHOST::~TestSliceGMHOST()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestSliceGMHOST::allTests()
    {
    TestCuda::allTests();

    TEST_ADD(TestSliceGMHOST::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestSliceGMHOST::testSpecial()
    {
    showTitle("Test special ");

    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    const bool IS_CHECK_HEURISTIC = false;
    dim3 dg(64, 1, 1);
    dim3 db(1024, 1, 1);
    Grid grid(dg, db, IS_CHECK_HEURISTIC); //power 2

    test(grid);
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
long TestSliceGMHOST::thresholdPerformanceFps()
    {
    return 1500; // cbi naif 2359 (tres trop variable!)
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

