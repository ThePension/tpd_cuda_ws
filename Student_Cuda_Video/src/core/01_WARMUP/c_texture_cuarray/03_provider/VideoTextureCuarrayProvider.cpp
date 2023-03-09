#include "VideoTextureCuarrayProvider.h"
#include "VideoTextureCuarray.h"

#include "Grid.h"
#include "Hardware.h"

#include "Autoroute.h"
#include "NeilPryde.h"
#include "Matrix22.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

VideoTextureCuarrayProvider::VideoTextureCuarrayProvider(bool loadOnlyOneImage) :
	Provider_uchar_A(loadOnlyOneImage)
    {
    // rien de plus
    }

VideoTextureCuarrayProvider::~VideoTextureCuarrayProvider()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Override
 */
Grid VideoTextureCuarrayProvider::grid()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    // TODO
    assert(false);
    Grid grid;

    return grid;
    }

/**
 * Override
 */
Animable_I<uchar>* VideoTextureCuarrayProvider::createAnimable(const Grid& grid , bool isVerbose)
    {
    IteratorImageGray_I* ptrIteratorImageGray = Autoroute::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = NeilPryde::getInstance()->iterator();
    //  IteratorImageGray_I* ptrIteratorImageGray = Matrix22::getInstance()->iterator();

    return new VideoTextureCuarray(grid, ptrIteratorImageGray);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
