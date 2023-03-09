#include "TestReductionGenericII.h"

#include "Hardware.h"
#include "ChronoFactory.h"
#include "Limits.h"

#include "ReductionIntIIProvider.h"
#include "PIntII.h"

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

TestReductionGenericII::TestReductionGenericII() : //
	TestCudaPower2(new ReductionIntIIProvider())
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
void TestReductionGenericII::allTests()
    {
    TestCudaPower2::allTests();

    TEST_ADD(TestReductionGenericII::testSpecialeMax);
    }

void TestReductionGenericII::testSpecialeMax()
    {
    showTitle("Test special max");

    const int DBX_MAX = 1024;
    const int DGX_MAX = PIntII().dgxMax(DBX_MAX);

    const bool IS_CHECK_HEURISTIC = false;
    dim3 dg(DGX_MAX, 1, 1);
    dim3 db(DBX_MAX, 1, 1); // power 2
    Grid grid(dg, db, IS_CHECK_HEURISTIC);

    test(grid);
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
long TestReductionGenericII::thresholdPerformanceFps()
    {
    return 50000; // cbi naif 109472 si avec all, 55000 si tout seul, strange
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

