#include "TestSliceSM.h"

#include "Hardware.h"
#include "ChronoFactory.h"
#include "Limits.h"

#include "SliceProviderSM.h"

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

TestSliceSM::TestSliceSM() : //
	TestCudaPower2(new SliceProviderSM())
    {
    enableTestMonoThread(true);
    enableTestMonoBlock(true);
    enableTestPerformance(true, thresholdPerformanceFps());
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 */
void TestSliceSM::allTests()
    {
    TestCudaPower2::allTests();

    TEST_ADD(TestSliceSM::testSpecialeMax);
    }

/**
 * <pre>
 * Dans la reduction IntraThread, avec le pattern d'entrelacement:
 *
 * 	s+=NB_THREAD
 *
 * Comme s est la pluspart du temps type int, pour des raisons de performance,
 * il y a un risque que
 *
 * 	s+NB_THREAD deborde le type  int
 *
 * notamment pour le thread de TID le plus elevé.
 *
 * Il ne faut donc pas prendre une grille trop grande, de telle sorte que
 *
 * 	1) TID reste en int
 * 	2) s+NBHREAD reste en int
 *
 * Pour que s+NBHREAD reste en int, il faut prendre le pire cas, le cas ou s est max(TID)=NB_THREAD=grid.threadCounts();
 *
 * 	s+NBHREAD reste en int  ssi NBHREAD+NBHREAD<=INT_MAX
 * 	    			ssi NBHREAD<= INT_MAX/2
 * </pre>
 */
void TestSliceSM::testSpecialeMax()
    {
    const int dgx = (Limits::MAX_INT / 1024) / 2; // ou 1024 est dbx

    showTitle("Test special max");

    const bool IS_CHECK_HEURISTIC=false;
    dim3 dg(dgx, 1, 1);
    dim3 db(1024, 1, 1);
    Grid grid(dg, db,IS_CHECK_HEURISTIC);

    test(grid);
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/


/**
 * static
 */
long TestSliceSM::thresholdPerformanceFps()
    {
    return 26000; // cbi naif 30379
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

