#include <iostream>
#include <stdlib.h>

#include "Matlab.h"
#include "Hardware.h"
#include "BruteForce.h"
#include "ProviderUse_I.h"

//Slice
#include "SliceProviderGMHOST.h"
#include "SliceProviderGM.h"
#include "SliceProviderSM.h"

//Montecarlo
#include "MontecarloProvider.h"
#include "MontecarloMultiProvider_thread.h"
#include "MontecarloMultiProvider_stream.h"

// Vector
#include "AddVectorProvider.h"
#include "AddVectorBistreamProvider.h"
#include "AddVectorTristreamProvider.h"
#include "VectorTools.h"

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void sliceGMHOST(Matlab* ptrMatlab);
static void sliceGM(Matlab* ptrMatlab);
static void sliceSM(Matlab* ptrMatlab);

static void montecarlo(Matlab* ptrMatlab);
static void montecarloMulti_thread(Matlab* ptrMatlab);
static void montecarloMulti_stream(Matlab* ptrMatlab);

static void addvector(Matlab* ptrMatlab);
static void addvectorBistream(Matlab* ptrMatlab);
static void addvectorTristream(Matlab* ptrMatlab);
static void addvectorTristream1a(Matlab* ptrMatlab);
static void addvectorTristream1b(Matlab* ptrMatlab);
static void addvectorTristreamDebug(Matlab* ptrMatlab);

// Tools
static void bruteforce(ProviderUse_I* ptrProviderUse , Matlab* ptrMatlab , const PlotType& plotType , double durationMaxS);
static void bruteforceReduction(ProviderUse_I* ptrProviderUse , Matlab* ptrMatlab , const PlotType& plotType , double durationMaxS);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainBrutforce()
    {
    cout << "\n[Bruteforce] mode" << endl;

    Matlab matlab;

    // one at a time!

    // Slice
	{
	sliceGMHOST(&matlab);
	// sliceGM(&matlab);
	// sliceSM(&matlab);
	}

    // Montecarlo
	{
	//montecarlo(&matlab);
	//montecarloMulti_thread(&matlab);
	//montecarloMulti_stream(&matlab);
	}

    // vector
	{
	//addvectorTristream(&matlab);
	//addvectorBistream(&matlab);
	//addvector(&matlab);
	}

    matlab.play();

    cout << "\n[BruteForce] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void sliceGMHOST(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    SliceProviderGMHOST sliceProviderGMHOST;

    bruteforce(&sliceProviderGMHOST, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void sliceGM(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    SliceProviderGM sliceProviderGM;

    // brutefore: cas special dg et db power 2
	{
	const int WARP_SIZE = Hardware::getWarpSize();

	// dg
	Iterator iteratorDGx(WARP_SIZE, 1024, 2, Operator::MULTIPLY); // (min,max,step) // power 2

	// db
	Iterator iteratorDBx(WARP_SIZE, 1024, 2, Operator::MULTIPLY); // (min,max,step) // power 2

	// gridMaillage
	GridMaillage gridMaillage(iteratorDGx, iteratorDBx);

	BruteForce::run(&sliceProviderGM, &gridMaillage, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
	}
    }

void sliceSM(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    SliceProviderSM sliceProviderSM;

    bruteforceReduction(&sliceProviderSM, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void montecarlo(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    MontecarloProvider montecarloProvider;

    bruteforceReduction(&montecarloProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void montecarloMulti_thread(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    MontecarloMultiProvider_thread montecarloProviderMulti;

    bruteforceReduction(&montecarloProviderMulti, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void montecarloMulti_stream(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    MontecarloMultiProvider_stream montecarloProviderMulti;

    bruteforceReduction(&montecarloProviderMulti, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void addvector(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    AddVectorProvider addVectorProvider;

    bruteforce(&addVectorProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void addvectorBistream(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    AddVectorBistreamProvider addVectorBistreamProvider;

    bruteforce(&addVectorBistreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

/*--------------------------------------*\
 |*		Tristream		*|
 \*-------------------------------------*/

/**
 * Selon le cas il faut changer la taille du vecteur dans VectorTools.cpp, VectorTools::n()
 * Why? On veut se simplifier la vie, et pourvoir avoir des slices de tranches égales
 */
void addvectorTristream(Matlab* ptrMatlab)
    {
    addvectorTristream1a(ptrMatlab);
    //addvectorTristream1b(ptrMatlab);

    // addvectorTristreamDebug(ptrMatlab);
    }

/**
 * cas 1.a : #slice : 3 4 5 6 7 8 9 10 11 12 13 14 15
 */
void addvectorTristream1a(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    for (int nbSlice = 3; nbSlice <= 15; nbSlice++) // long
	{
	AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

	bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
	}
    }
/**
 * cas 1.b : #slice in [5,75] par pas de 5
 */
void addvectorTristream1b(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    for (int nbSlice = 5; nbSlice <= 75; nbSlice += 5)
	{
	AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

	bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
	}
    }

void addvectorTristreamDebug(Matlab* ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    int nbSlice = 25; // 15 20 30 75 cas 1.b
    AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

    bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

/*-----------------------------------*\
 |*		Tools	        	*|
 \*-----------------------------------*/

/**
 * db power2
 */
void bruteforceReduction(ProviderUse_I* ptrProviderUse , Matlab* ptrMatlab , const PlotType& plotType , double durationMaxS)
    {
    // Hardware
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();
    const int NB_THREAD_BLOCK_MAX = Hardware::getMaxThreadPerBlock();
    const int WARP_SIZE = Hardware::getWarpSize();

    // dg
    Iterator iteratorDGx(MP, 10 * MP, MP, Operator::ADD); // (min,max,step)

    // db
    //  Iterator iteratorDBx(WARP_SIZE, NB_THREAD_BLOCK_MAX, 2, Operator::MULTIPLY); // power2 (reduction)
    Iterator iteratorDBx(CORE_MP, NB_THREAD_BLOCK_MAX, 2, Operator::MULTIPLY); // power2 (reduction)

    // gridMaillage
    GridMaillage gridMaillage(iteratorDGx, iteratorDBx);

    BruteForce::run(ptrProviderUse, &gridMaillage, ptrMatlab, plotType, durationMaxS);
    }

void bruteforce(ProviderUse_I* ptrProviderUse , Matlab* ptrMatlab , const PlotType& plotType , double durationMaxS)
    {
    // Hardware
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();
    const int NB_THREAD_BLOCK_MAX = Hardware::getMaxThreadPerBlock();
    const int WARP_SIZE = Hardware::getWarpSize();

    // dg
    Iterator iteratorDGx(MP, 10 * MP, MP, Operator::ADD); // (min,max,step)

    // db
    Iterator iteratorDBx(CORE_MP, NB_THREAD_BLOCK_MAX, CORE_MP, Operator::ADD); // (min,max,step)

    // gridMaillage
    GridMaillage gridMaillage(iteratorDGx, iteratorDBx);

    BruteForce::run(ptrProviderUse, &gridMaillage, ptrMatlab, plotType, durationMaxS);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

