#include "RipplingProvider.h"
#include "Rippling.h"

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
Grid RipplingProvider::grid()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    Grid grid;//TODO

    assert(false); //to be removed once implemented

    return grid;
    }

/**
 * Override
 */
Animable_I<uchar4>* RipplingProvider::createAnimable(const Grid& grid , bool isVerbose)
    {
    // Animation;
    float dt = 2 * PI / 10;

    // Dimension
    int w = 16 * 60;
    int h = 16 * 60;

    return new Rippling(grid, w, h, dt, isVerbose);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
