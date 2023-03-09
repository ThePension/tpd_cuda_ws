#include "RaytracingProviderSM.h"
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
Grid RaytracingProviderSM::grid()
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
Animable_I<uchar4>* RaytracingProviderSM::createAnimable(const Grid& grid , bool isVerbose)
    {
    return RaytracingCreator::createSM(grid, isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
