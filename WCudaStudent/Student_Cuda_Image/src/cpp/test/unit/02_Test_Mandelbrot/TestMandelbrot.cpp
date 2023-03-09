#include "TestMandelbrot.h"

#include "MandelbrotProvider.h"

#include "real.h"
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

TestMandelbrot::TestMandelbrot() :
	TestCuda((ProviderUse_I*)new MandelbrotProvider())
    {
    enableTestPerformance(true, thresholdPerformanceFps());
    }


/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestMandelbrot::allTests()
    {
    TEST_ADD(TestCuda::testPerformance);// @suppress("Invalid overload")
    TEST_ADD(TestMandelbrot::testSpecial);
    }

/**
 * si on le met pas probleme de title dans le html (workaround for this, le test en soi n'est pas important
 */
void TestMandelbrot::testSpecial()
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
long TestMandelbrot::thresholdPerformanceFps()
    {
    #ifdef MANDELBROT_DOUBLE
	return 10000; // cbi naif 14500
   #endif

   #ifdef MANDELBROT_FLOAT
	return 18000; // cbi naif 22000
   #endif

    #ifdef MANDELBROT_HALF
	return 23000; // cbi naif  285000
   #endif

   assert(false); // ne doit jamais arriver
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

