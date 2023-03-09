#include "PLongII.h"

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

PLongII::PLongII()
    {
    // rien
    }

PLongII::~PLongII()
    {
    // rien
    }

/*--------------------------------------*\
|*		Override		*|
 \*-------------------------------------*/

/**
 *	Soit n le nombre totale de  thread
 *	Le resultat de la reduction n(n-1)/2 ne doit pas depasser le type long
 *
 *	Example:
 *		db.x=1024 => DGX_MAX=4194303
 */
bool PLongII::isSizeMaxOK(const Grid& grid)
    {
    long dgx = grid.dg.x;
    long dbx = grid.db.x;
    long n = dgx * dbx;

    if (n % 2 == 0)
	{
	return (n / 2) * (n - 1) <= Limits::MAX_LONG;
	}
    else
	{
	return n * ((n - 1) / 2) <= Limits::MAX_LONG;
	}
    }

/**
 * dbx = 1024
 * pour pas de debordement du type long dans le protocole II avec db=1024
 */
int PLongII::dgxMax()  const
    {
    return 4194303;
    }

/**
 *  n(n-1)/2 ou n = nbThreadTotal
 */
long PLongII::resultatTheorique(const Grid& grid)
    {
// attention a ne pas deborder du type int, effectuer les operations dans le bon ordre
// Rappel :
//		(R1) un nombre pair est divisible par 2
//		(R2) un nombre impair -1 devient pair

    long n = grid.threadCounts();
    long result = -1;

    if (n % 2 == 0)
	{
	result = (n / 2) * (n - 1);
	}
    else
	{
	result = n * ((n - 1) / 2);
	}

    // check en long
	{
	assert(result>=0 && result <= Limits::MAX_LONG); // ne sert a pas grand chose si deborde le type long , sans etre en negatif
	}

    return result;
    }


/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
