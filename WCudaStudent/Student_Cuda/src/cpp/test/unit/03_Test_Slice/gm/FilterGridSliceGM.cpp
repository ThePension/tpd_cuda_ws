#include "FilterGridSliceGM.h"

#include <iostream>

#include "Maths.h"
#include "SliceNumber.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

FilterGridSliceGM::FilterGridSliceGM() : //
	FilterGrid()
    {
    // rien
    }

FilterGridSliceGM::~FilterGridSliceGM()
    {
    // rien
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 * true -> conserver
 */
bool FilterGridSliceGM::isAccept(const Grid& grid)
    {
    return isAcceptQuantity(grid) && isAcceptPrecision(grid);
    }

/*--------------------------------------*\
|*		private		*|
 \*-------------------------------------*/

/**
/**
 * power2 : dg*db (reductionIntraThread)
 *
 * pas plus de thread que de slice
 */
bool FilterGridSliceGM::isAcceptQuantity(const Grid& grid)
    {
    int dgx = grid.dg.x;
    int dbx = grid.db.x;

    long nbThreads = grid.threadCounts();
    long nbSlices = SliceNumber::nbSlice();

    return Maths::isPower2(dgx * dbx) && nbThreads <= nbSlices;
    }

/**
 * pas assez de precision pour 1e-2
 */
bool FilterGridSliceGM::isAcceptPrecision(const Grid& grid)
    {
    int dgx = grid.dg.x;
    int dbx = grid.db.x;

    return !(dgx == 2 && dbx == 2);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
