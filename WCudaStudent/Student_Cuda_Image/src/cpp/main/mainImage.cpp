#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Args.h"
#include "cudas.h"

#include "RipplingProvider.h"
#include "MandelbrotProvider.h"
#include "RaytracingProviderGM.h"
#include "RaytracingProviderSM.h"
#include "RaytracingProviderCM.h"
#include "RaytracingProviderCM2SM.h"

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

    // ImageOption : (boolean,boolean) : (isSelection ,isAnimation,isOverlay,isShowHelp)
    ImageOption zoomable(true, true, true, true);
    ImageOption nozoomable(false, true, false, false);

    Viewer<RipplingProvider> rippling(nozoomable, 0, 0); // imageOption px py
    Viewer<MandelbrotProvider> mandelbrot(zoomable, 0, 0);
    Viewer<RaytracingProviderGM> raytracingGM(nozoomable, 0, 0);
    Viewer<RaytracingProviderCM> raytracingCM(nozoomable, 0, 0);
    Viewer<RaytracingProviderSM> raytracingSM(nozoomable, 0, 0);
    Viewer<RaytracingProviderCM2SM> raytracingCM2SM(nozoomable, 0, 0);

    // Common
    gpu::GLUTImageViewers::runALL(); // Bloquant, Tant qu'une fenetre est ouverte

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

