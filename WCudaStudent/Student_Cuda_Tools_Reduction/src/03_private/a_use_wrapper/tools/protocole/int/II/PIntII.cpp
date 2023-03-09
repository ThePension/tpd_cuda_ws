#include "PIntII.h"

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

PIntII::PIntII()
    {
    // rien
    }

PIntII::~PIntII()
    {
    // rien
    }

/*--------------------------------------*\
|*		Override		*|
 \*-------------------------------------*/

/**
 * static 63 pour dbx=1024
 */
int PIntII::dgxMax(int dbx) const
    {
    // check
	{
	const int MAX_THREAD_BLOCK = Hardware::getMaxThreadPerBlock();
	assert(dbx >= 1 && dbx <= MAX_THREAD_BLOCK);
	}

    const bool IS_V1 = false;

    if (IS_V1)
	{
	const long underL = (long)1 + ((long)8 * (long)Limits::MAX_INT);
	const double underD = (double)underL;
	const long dgxMax = (long)((-1 + sqrt(underD)) / (double)2); // 65535 linux 64 bits

	//    cerr<<"underL"<<underL<<endl;
	//    cerr<<"underD"<<underD<<endl;
	//    cerr<<"dgxMax"<<dgxMax<<endl;

	return dgxMax / dbx;
	}
    else
	{
	return 65535 / dbx;
	}
    }

/**
 *	Soit n le nombre totale de  thread
 *	Le resultat de la reduction n(n-1)/2 ne doit pas depasser le type int
 *
 *	Example:
 *		db.x=1024 => DGX_MAX=63
 */
bool PIntII::isSizeMaxOK(const Grid& grid)
    {
    long dgx = grid.dg.x;
    long dbx = grid.db.x;
    long n = dgx * dbx;

    long MAX_INT = (long)Limits::MAX_INT;

    if (n % 2 == 0)
	{
	return (n / 2) * (n - 1) <= MAX_INT;
	}
    else
	{
	return n * ((n - 1) / 2) <= MAX_INT;
	}
    }

/**
 *  n(n-1)/2 ou n = nbThreadTotal
 */
int PIntII::resultatTheorique(const Grid& grid)
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
	const long MAX_INT = (long)Limits::MAX_INT; //pour que si on deborde le
	assert(result <= Limits::MAX_INT);
	}

    return (int)result;
    }

/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
