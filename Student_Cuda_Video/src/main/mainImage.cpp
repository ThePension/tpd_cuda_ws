#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "cudas.h"

#include "Videos.h"

#include "VideoBaseProvider.h"
#include "VideoTextureGMProvider.h"
#include "VideoTextureCuarrayProvider.h"
#include "VideoSurfaceProvider.h"

//#include "ConvolutionProviderGauss.h"
//#include "ConvolutionProviderDX.h"
//#include "ConvolutionProviderDY.h"
//#include "ConvolutionProviderIdentity.h"
//#include "ConvolutionProviderNetteter.h"
//#include "ConvolutionProviderContour.h"
//
//#include "ConvolutionTexProviderGauss.h"

#include "Args.h"
#include "Viewer.h"

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int mainImage(const Args& args)
    {
    cout << "\n[Image] mode" << endl;

    gpu::GLUTImageViewers::init(args.argc, args.argv); //only once

    // Videos::preloadONE();
    Videos::preloadALL();

    // ImageOption : (boolean,boolean) : (isSelection ,isAnimation)
    ImageOption zoomable(true);
    ImageOption nozoomable(false);

    Viewer<VideoBaseProvider> videoBase(nozoomable, 0, 0); // imageOption px py
    Viewer<VideoTextureGMProvider> videoTextureGM(nozoomable, 25, 25); // imageOption px py
    Viewer<VideoTextureCuarrayProvider> videoTexture(nozoomable, 25, 25); // imageOption px py
    Viewer<VideoSurfaceProvider> videoSurface(nozoomable, 25, 25); // imageOption px py

//
//   Viewer<ConvolutionProviderGauss> convolutionGauss(nozoomable, 50, 50); // imageOption px py
//    Viewer<ConvolutionProviderDX> convolutionDX(nozoomable, 75, 75); // imageOption px py
//    Viewer<ConvolutionProviderDY> convolutionDY(nozoomable, 100, 100); // imageOption px py
//    Viewer<ConvolutionProviderNetteter> convolutionNetteter(nozoomable, 125, 125); // imageOption px py
//    Viewer<ConvolutionProviderIdentity> convolutionIdentity(nozoomable, 150, 150); // imageOption px py
//    Viewer<ConvolutionProviderContour> convolutionContour(nozoomable, 175, 175); // imageOption px py
//
//   Viewer<ConvolutionTexProviderGauss> convolutionTexGauss(nozoomable, 0, 0); // imageOption px py

    // Common
    gpu::GLUTImageViewers::runALL(); // Bloquant, Tant qu'une fenetre est ouverte

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

