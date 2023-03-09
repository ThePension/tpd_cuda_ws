#include "VideoTextureGMProvider.h"
#include "VideoTextureGM.h"

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

VideoTextureGMProvider::VideoTextureGMProvider(bool loadOnlyOneImage) :
	Provider_uchar_A(loadOnlyOneImage)
    {
    // rien de plus
    }

VideoTextureGMProvider::~VideoTextureGMProvider()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Override
 */
Grid VideoTextureGMProvider::grid() // gridMinMax
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
Animable_I<uchar>* VideoTextureGMProvider::createAnimable(const Grid& grid , bool isVerbose)
    {
    //IteratorImageGray_I* ptrIteratorImageGray = Autoroute::getInstance()->iterator();
    IteratorImageGray_I* ptrIteratorImageGray = Matrix22::getInstance()->iterator();
    //IteratorImageGray_I* ptrIteratorImageGray = NeilPryde::getInstance()->iterator();

    return new VideoTextureGM(grid, ptrIteratorImageGray);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
