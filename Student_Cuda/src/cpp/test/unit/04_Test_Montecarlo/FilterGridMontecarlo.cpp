#include "FilterGridMontecarlo.h"

#include <iostream>

#include "Maths.h"
#include "MontecarloUseTools.h"
#include "Hardware.h"

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

FilterGridMontecarlo::FilterGridMontecarlo() : //
	FilterGrid()
    {
    // rien
    }

FilterGridMontecarlo::~FilterGridMontecarlo()
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
bool FilterGridMontecarlo::isAccept(const Grid& grid)
    {
    return enough(grid);
    }

/*--------------------------------------*\
|*		private		*|
 \*-------------------------------------*/

/**
 * <pre>
 * Warning:
 * 	(W1) il faut pas que le nombre de thread soit plus grand que le nombre de dar
 * 	(W2) il faut éviter les petites grid peut performante, pour eviter que les tests soit trop longs!
 * </pre>
 */
bool FilterGridMontecarlo::enough(const Grid& grid)
    {
    int dgx = grid.dg.x;
    int dbx = grid.db.x;

    long nbThreads = grid.threadCounts();
    entier nbDar = MontecarloUseTools::nbDarTotalTest();

    return dgx >= Hardware::getMPCount() && dbx >= 32 && nbThreads < nbDar;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
