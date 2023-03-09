#include "TestReductionGenericLongII.h"

#include "Hardware.h"
#include "ChronoFactory.h"
#include "Limits.h"
#include "Iterator.h"

#include "ReductionLongIIProvider.h"
#include "PLongII.h"
#include "PIntII.h"

#include <iostream>

using std::cerr;
using std::endl;
using std::cout;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestReductionGenericLongII::TestReductionGenericLongII() : //
	TestCudaPower2(new ReductionLongIIProvider())
    {
    enableChrono(false);

   // enableTestPerformance(true, thresholdPerformanceFps());// pas celui la , car utilise la grid max et fps < 1
    enableTestMonoBlock(true);
    enableTestMonoThread(true);
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestReductionGenericLongII::allTests()
    {
    TestCudaPower2::allTests(); // ok en long, mais ko en int

    TEST_ADD(TestReductionGenericLongII::testspecialGridDGXMAX);
    TEST_ADD(TestReductionGenericLongII::testSpecialGrid2);
    TEST_ADD(TestReductionGenericLongII::testSpecialeMax);
    TEST_ADD(TestReductionGenericLongII::testSpecialPerformance);
    }

void TestReductionGenericLongII::testSpecialeMax()
    {
    showTitle("Test special max");

    const int DBX_MAX = 1024;
    const int DGX_MAX = PLongII().dgxMax();

    const bool IS_CHECK_HEURISTIC = false;
    dim3 dg(DGX_MAX, 1, 1);
    dim3 db(DBX_MAX, 1, 1); // power 2
    Grid grid(dg, db, IS_CHECK_HEURISTIC);

    test(grid);
    }

void TestReductionGenericLongII::testspecialGridDGXMAX()
    {
    const int DBX_MAX=1024;
    const int DGX_MAX = PLongII().dgxMax();

    Iterator iteratorDGX(DGX_MAX, DGX_MAX, 2, Operator::MULTIPLY); // (min,max,step) aucune variation
    Iterator iteratorDBX(2, DBX_MAX, 2, Operator::MULTIPLY); // (min,max,step) power2

    string title = "Test Grid DGX_MAX";

    testGridTools(&iteratorDGX, &iteratorDBX, title);
    }

void TestReductionGenericLongII::testSpecialGrid2()
    {
    const int DBX_MAX=1024;
    const int DGX_MAX = PLongII().dgxMax();

    Iterator iteratorDGX(1, DGX_MAX, 2, Operator::MULTIPLY); // (min,max,step)
    Iterator iteratorDBX(2, DBX_MAX, 2, Operator::MULTIPLY); // (min,max,step) power2

    string title = "Test Grid Special 2";

    testGridTools(&iteratorDGX, &iteratorDBX, title);
    }

void TestReductionGenericLongII::testSpecialPerformance()
    {
    const int DBX_MAX = 1024;
    const int MP = Hardware::getMPCount();
    const int DGX = MP * 20;

    // check
	{
	const int DGX_MAX_LONG =PLongII().dgxMax();
	const int DGX_MAX_INT = PIntII().dgxMax(DBX_MAX);
	assert(DGX <= DGX_MAX_LONG);
	assert(DGX > DGX_MAX_INT);
	}

    dim3 dg(DGX, 1, 1);
    dim3 db(DBX_MAX, 1, 1); // power 2
    Grid grid(dg, db);

    testPerformance(grid,thresholdPerformanceFps());
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
long TestReductionGenericLongII::thresholdPerformanceFps()
    {
    return 1500; // cbi naif 2600
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

