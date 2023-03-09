#include "TestReductionAddI.h"

#include "Limits.h"
#include "Hardware.h"
#include "ChronoFactory.h"

#include "ReductionAddIntIProvider.h"
#include "PIntI.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestReductionAddI::TestReductionAddI() : //
	TestCudaPower2(new ReductionAddIntIProvider())
    {
    enableChrono(false);
    enableTestPerformance(true, thresholdPerformanceFps());
    enableTestMonoBlock(true);
    enableTestMonoThread(true);
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestReductionAddI::allTests()
    {
    TestCudaPower2::allTests();

    TEST_ADD(TestReductionAddI::testSpecialeMax);
    }

void TestReductionAddI::testSpecialeMax()
    {
    showTitle("Test special max");

    const int DBX_MAX = 1024;
    const int DGX_MAX = PIntI().dgxMax(DBX_MAX);

    const bool IS_CHECK_HEURISTIC = false;
    dim3 dg(DGX_MAX, 1, 1);
    dim3 db(DBX_MAX, 1, 1); //power 2
    Grid grid(dg, db, IS_CHECK_HEURISTIC);

    test(grid);
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
long TestReductionAddI::thresholdPerformanceFps()
    {
    return 10; // cbi naif 19
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

