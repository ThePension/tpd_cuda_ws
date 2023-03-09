#include <iostream>
#include <stdlib.h>

#include "Benchmark.h"

// Slice
#include "SliceGmHostUse.h"
#include "SliceGmUse.h"
#include "SliceSmUse.h"

// Montecarlo
#include "MontecarloUse.h"
#include "MontecarloMultiUse_thread.h"
#include "MontecarloMultiUse_stream.h"

// Vector
#include "AddVectorUse.h"
#include "AddVectorBistreamUse.h"
#include "AddVectorTristreamUse.h"
#include "VectorTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void sliceGMHOST();
static void sliceGM();
static void sliceSM();

static void montecarlo();
static void montecarloMulti_thread();
static void montecarloMulti_stream();

static void addvector();
static void addvectorBistream();
static void addvectorTristream();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainBenchmark()
    {
    cout << "\n[Benchmark] mode" << endl;

    // one at a time!

    // Slice
	{
	sliceGMHOST();
	//sliceGM();
	//sliceSM();
	}

    // Montecarlo
	{
	//montecarlo();
	//montecarloMulti_thread();
	//montecarloMulti_stream();
	}

    // Vector
	{
	//addvectorTristream();
	//addvectorBistream();
	//addvector();
	}

    cout << "\n[Benchmark] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void sliceGMHOST()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    SliceGmHostUse sliceGmHostUse(IS_VERBOSE);

    Benchmark::run(sliceGmHostUse.getRunnableGPU(), DURATION_MAX_S);
    }

void sliceGM()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    SliceGmUse sliceGmUse(IS_VERBOSE);

    Benchmark::run(sliceGmUse.getRunnableGPU(), DURATION_MAX_S);
    }

void sliceSM()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    SliceSmUse sliceSmUse(IS_VERBOSE);

    Benchmark::run(sliceSmUse.getRunnableGPU(), DURATION_MAX_S);
    }

void montecarlo()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    MontecarloUse montecarloUse(IS_VERBOSE);

    Benchmark::run(montecarloUse.getRunnableGPU(), DURATION_MAX_S);
    }

void montecarloMulti_thread()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    MontecarloMultiUse_thread montecarloMultiUse(IS_VERBOSE);

    Benchmark::run(montecarloMultiUse.getRunnableGPU(), DURATION_MAX_S);
    }

void montecarloMulti_stream()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    MontecarloMultiUse_stream montecarloMultiUse(IS_VERBOSE);

    Benchmark::run(montecarloMultiUse.getRunnableGPU(), DURATION_MAX_S);
    }

void addvector()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    AddVectorUse addVectorUse(IS_VERBOSE);

    Benchmark::run(addVectorUse.getRunnableGPU(), DURATION_MAX_S);
    }

void addvectorBistream()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    AddVectorBistreamUse addVectorBistreamUse(IS_VERBOSE);

    Benchmark::run(addVectorBistreamUse.getRunnableGPU(), DURATION_MAX_S);
    }

void addvectorTristream()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    int nbSlice = 20;

    AddVectorTristreamUse addVectorTristreamUse(nbSlice, IS_VERBOSE);

    Benchmark::run(addVectorTristreamUse.getRunnableGPU(), DURATION_MAX_S);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

