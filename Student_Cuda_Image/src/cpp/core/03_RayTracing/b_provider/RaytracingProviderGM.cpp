#include "RaytracingProviderGM.h"
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
Grid RaytracingProviderGM::grid()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    Grid grid; // TODO Rippling
    assert(false); //to be removed once implemented

    return grid;
    }

/**
 * Override
 */
Animable_I<uchar4>* RaytracingProviderGM::createAnimable(const Grid& grid , bool isVerbose)
    {
    return RaytracingCreator::createGM(grid, isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
