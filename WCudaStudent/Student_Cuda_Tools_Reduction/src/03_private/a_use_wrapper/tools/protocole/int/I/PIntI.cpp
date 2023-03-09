#include "PIntI.h"

#include <iostream>

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

PIntI::PIntI()
    {
    // rien
    }

PIntI::~PIntI()
    {
    // rien
    }

/*--------------------------------------*\
|*		Override		*|
 \*-------------------------------------*/

/**
 * Soit n le nombre totale de  thread
 * Le resultat de la reduction est n
 *
 * Pour ne pas depasser le type int
 */
bool PIntI::isSizeMaxOK(const Grid& grid)
    {
    long dgx = grid.dg.x;
    long dbx = grid.db.x;
    long n = dgx * dbx;

    const long MAX_INT=(long)Limits::MAX_INT;

    return n <= MAX_INT;// comparaison en long
    }

/**
 * Soit n le nombre totale de  thread
 * Le resultat de la reduction est n
 *
 * Pour ne pas depasser le type int
 */
int PIntI::dgxMax(int dbx) const
    {
    // check
   	{
   	const int MAX_THREAD_BLOCK = Hardware::getMaxThreadPerBlock();
   	assert(dbx >= 1 && dbx <= MAX_THREAD_BLOCK);
   	}

    // dbx*dgx<= Limits::MAX_INT
    return Limits::MAX_INT / dbx;
    }

/**
 * Soit n le nombre totale de  thread
 * Le resultat de la reduction est n
 */
int PIntI::resultatTheorique(const Grid& grid)
    {
    return grid.threadCounts();
    }

/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
