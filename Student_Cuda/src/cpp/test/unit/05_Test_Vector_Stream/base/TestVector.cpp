#include "TestVector.h"

#include "Hardware.h"
#include "ChronoFactory.h"
#include "Limits.h"

#include "AddVectorProvider.h"

#include <assert.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestVector::TestVector() : //
	TestCuda(new AddVectorProvider())
    {
    // juste pour prendre moins de temps
	{
	const int MP = Hardware::getMPCount();
	const int CORE_MP = Hardware::getMaxThreadPerBlock();

	Iterator iteratorDgx(
	    {
	    MP, MP * 10, MP, Operator::ADD
	    // min max pas
		});

	Iterator iteratorDbx(
	    {
	    2, Hardware::getMaxThreadPerBlock(), 2, Operator::MULTIPLY
	    // min max pas
		});

	setDbx(iteratorDbx);
	setDgx(iteratorDgx);
	setDgx(16); // test simple // power2
	}

    enableTestMonoThread(false);
    enableTestMonoBlock(false);
    enableTestPerformance(true, thresholdPerformanceFps());
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestVector::allTests()
    {
    TestCuda::allTests();

    TEST_ADD(TestVector::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestVector::testSpecial()
    {
    showTitle("Test special");

    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    const bool IS_CHECK_HEURISTIC = false;
    dim3 dg(3, 1, 1);
    dim3 db(32, 1, 1);
    Grid grid(dg, db,IS_CHECK_HEURISTIC);

    test(grid);
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
long TestVector::thresholdPerformanceFps()
    {
    return 80; // cbi naif 104
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

