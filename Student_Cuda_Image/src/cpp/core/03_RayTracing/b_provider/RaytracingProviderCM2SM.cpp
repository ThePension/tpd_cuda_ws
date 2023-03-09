#include "RaytracingProviderCM2SM.h"
#include "RaytracingCreator.h"

#include "Hardware.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
Grid RaytracingProviderCM2SM::grid()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    Grid grid; // TODO Raytracing
    assert(false); //to be removed once implemented

    return grid;
    }

/**
 * Override
 */
Animable_I<uchar4>* RaytracingProviderCM2SM::createAnimable(const Grid& grid , bool isVerbose)
    {
    return RaytracingCreator::createCM2SM(grid, isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
