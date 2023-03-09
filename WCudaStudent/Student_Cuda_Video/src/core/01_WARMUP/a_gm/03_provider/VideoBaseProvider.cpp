#include "VideoBaseProvider.h"
#include "VideoBase.h"

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

VideoBaseProvider::VideoBaseProvider(bool loadOnlyOneImage) :
	Provider_uchar_A(loadOnlyOneImage)
    {
    // rien de plus
    }

VideoBaseProvider::~VideoBaseProvider()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Override
 */
Grid VideoBaseProvider::grid() // gridMinMax
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
Animable_I<uchar>* VideoBaseProvider::createAnimable(const Grid& grid , bool isVerbose)
    {
    IteratorImageGray_I* ptrIteratorImageGray = Autoroute::getInstance()->iterator();
   //IteratorImageGray_I* ptrIteratorImageGray = Matrix22::getInstance()->iterator(); // utile pour debuguer et valider
    //IteratorImageGray_I* ptrIteratorImageGray = NeilPryde::getInstance()->iterator();

    return new VideoBase(grid, ptrIteratorImageGray);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
