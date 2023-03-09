#include <iostream>

#include "CudaContext.h"
#include "Limits.h"

using std::cout;
using std::cerr;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Imported 					*|
 \*---------------------------------------------------------------------*/

extern int mainUse();
extern int mainTest();
extern int mainBenchmark();
extern int mainBrutforce();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int main(int argc , char** argv)
    {
    Limits::show();

    CudaContext cudaContext;

    // public
	{
	cudaContext.deviceId = 1; //  in [0,2] width Server Cuda3
	cudaContext.launchMode = LaunchModeMOO::USE; // USE TEST  BENCHMARK  FORCEBRUT

	cudaContext.deviceDriver = DeviceDriver::LOAD_ALL; // LOAD_CURRENT   LOAD_ALL
	cudaContext.deviceInfo = DeviceInfo::ALL_SIMPLE;   // NONE  ALL  ALL_SIMPLE  CURRENT
	}

    // private
	{
	cudaContext.mainUse = mainUse;
	cudaContext.mainTest = mainTest;
	cudaContext.mainBenchmark = mainBenchmark;
	cudaContext.mainBrutforce = mainBrutforce;
	}

    return cudaContext.process();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

