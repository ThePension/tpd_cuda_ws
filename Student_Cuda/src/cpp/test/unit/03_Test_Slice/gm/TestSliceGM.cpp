#include "TestSliceGM.h"

#include "Limits.h"
#include "Hardware.h"
#include "Maths.h"
#include "Iterator.h"
#include "SliceNumber.h"
#include "ChronoFactory.h"

#include "SliceProviderGM.h"

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

TestSliceGM::TestSliceGM() :
	TestCuda(new SliceProviderGM())
    {
    Iterator iteratorDgx(
	{
	2, 1024, 2, Operator::MULTIPLY
	// min max pas
	    });

    Iterator iteratorDbx(
	{
	2, Hardware::getMaxThreadPerBlock(), 2, Operator::MULTIPLY
	// min max pas
	    });

    setDbx(iteratorDbx);
    setDgx(iteratorDgx);
    setDgx(128); // test simple // power2

    this->ptrFilterGridSliceGM = new FilterGridSliceGM();
    addFilter(ptrFilterGridSliceGM);

    enableTestMonoBlock(true);
    enableTestMonoThread(true);
    enableTestPerformance(true, thresholdPerformanceFps());
    }

TestSliceGM::~TestSliceGM()
    {
    delete ptrFilterGridSliceGM;
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestSliceGM::allTests()
    {
    TestCuda::allTests();

    TEST_ADD(TestSliceGM::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestSliceGM::testSpecial()
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
long TestSliceGM::thresholdPerformanceFps()
    {
    return 12000; // cbi naif 13349
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

