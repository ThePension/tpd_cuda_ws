#include <iostream>
#include <stdlib.h>

#include "Videos.h"

#include "VideoBaseProvider.h"
#include "VideoTextureGMProvider.h"
#include "VideoTextureCuarrayProvider.h"
#include "VideoSurfaceProvider.h"

//#include "ConvolutionProviderGauss.h"
//#include "ConvolutionTexProviderGauss.h"

#include "BenchmarkImage.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void videoBase();
static void videoTextureGM();
static void videoTextureCuarray();
static void videoSurface();

//static void convolutionGauss();
//static void convolutionTexGauss();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int mainBenchmark()
    {
    cout << "\n[Benchmark] mode" << endl;

    Videos::preloadONE();

    // Attention : Un a la fois seulement!

    videoBase();
    videoTextureGM();
    videoTextureCuarray();
    videoSurface();

//    convolutionGauss();
//    convolutionTexGauss();

    cout << "\n[Benchmark] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void videoBase()
    {
    const double DURATION_MAX_S = 8;

    bool loadOnlyOneImage = true;
    VideoBaseProvider provider(loadOnlyOneImage);

    BenchmarkImage<uchar>::run(&provider, DURATION_MAX_S);
    }

void videoTextureGM()
    {
    const double DURATION_MAX_S = 8;

    bool loadOnlyOneImage = true;
    VideoTextureGMProvider provider(loadOnlyOneImage);

    BenchmarkImage<uchar>::run(&provider, DURATION_MAX_S);
    }

void videoTextureCuarray()
    {
    const double DURATION_MAX_S = 8;

    bool loadOnlyOneImage = true;
    VideoTextureCuarrayProvider provider(loadOnlyOneImage);

    BenchmarkImage<uchar>::run(&provider, DURATION_MAX_S);
    }

void videoSurface()
    {
    const double DURATION_MAX_S = 8;

    bool loadOnlyOneImage = true;
    VideoSurfaceProvider provider(loadOnlyOneImage);

    BenchmarkImage<uchar>::run(&provider, DURATION_MAX_S);
    }

/*--------------------------------------*\
 |*		convolution		*|
 \*-------------------------------------*/

//void convolutionGauss()
//    {
//    const double DURATION_MAX_S = 8;
//
//    bool loadOnlyOneImage = true;
//    ConvolutionProviderGauss provider(loadOnlyOneImage);
//
//    BenchmarkImage<uchar>::run(&provider, DURATION_MAX_S);
//    }
//
//void convolutionTexGauss()
//    {
//    const double DURATION_MAX_S = 8;
//
//    bool loadOnlyOneImage = true;
//    ConvolutionTexProviderGauss provider(loadOnlyOneImage);
//
//    BenchmarkImage<uchar>::run(&provider, DURATION_MAX_S);
//    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

