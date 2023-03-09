#include <iostream>

#include "CudaContextSimple.h"
#include "Limits.h"

using std::cout;
using std::cerr;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Imported 					*|
 \*---------------------------------------------------------------------*/

extern int mainCore(const Args& args);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int main(int argc , char** argv)
    {
    //Limits::show();

    CudaContextSimple cudaContext;

    // public
	{
	cudaContext.deviceId = 0; //  in [0,2] width Server Cuda3

	cudaContext.deviceDriver = DeviceDriver::LOAD_CURRENT; // LOAD_CURRENT   LOAD_ALL
	cudaContext.deviceInfo = DeviceInfo::ALL_SIMPLE;   // NONE  ALL  ALL_SIMPLE  CURRENT
	}

    // private
	{
	cudaContext.args.argc = argc;
	cudaContext.args.argv = argv;

	cudaContext.mainCore = mainCore;
	}

    return cudaContext.process();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/



