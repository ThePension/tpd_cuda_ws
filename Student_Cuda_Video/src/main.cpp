#include <iostream>

#include "CudaContextImage.h"
#include "Limits.h"

#include "Videos.h"

using std::cout;
using std::cerr;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Imported 					*|
 \*---------------------------------------------------------------------*/

extern int mainImage(const Args& args);
extern int mainBenchmark();
extern int mainBrutforce();
extern int mainTest();

/*----------------------------------------------------------------------*\
 |*			Private 					*|
 \*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int main(int argc , char** argv)
    {
    CudaContextImage cudaContext;

    // public
	{
	cudaContext.deviceId = 2; //  in [0,2] width Server Cuda3
	cudaContext.launchMode = LaunchModeImage::IMAGE; // IMAGE  BENCHMARKING  BRUTFORCE TESTING

	cudaContext.deviceDriver = DeviceDriver::LOAD_CURRENT; // LOAD_CURRENT   LOAD_ALL
	cudaContext.deviceInfo = DeviceInfo::ALL_SIMPLE;   // NONE  ALL  ALL_SIMPLE  CURRENT
	}

    // private
	{
	cudaContext.args.argc = argc;
	cudaContext.args.argv = argv;

	cudaContext.mainImage = mainImage;
	cudaContext.mainBenchmark = mainBenchmark;
	cudaContext.mainBrutforce = mainBrutforce;
	cudaContext.mainTest = mainTest;
	}

    int result = cudaContext.process();

    Videos::dispose();

    return result;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

