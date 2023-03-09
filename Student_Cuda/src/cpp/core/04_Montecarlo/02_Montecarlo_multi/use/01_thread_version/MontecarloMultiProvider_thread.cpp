#include "MontecarloMultiProvider_thread.h"

#include "MontecarloMultiUse_thread.h"
#include "MontecarloUseTools.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

MontecarloMultiProvider_thread::MontecarloMultiProvider_thread(float h , entier nbDar) : //
	h(h), //
	nbDar(nbDar)
    {
    // rien
    }

MontecarloMultiProvider_thread::MontecarloMultiProvider_thread() : //
	MontecarloMultiProvider_thread(MontecarloUseTools::H, MontecarloUseTools::nbDarTotalUse())
    {
    // rien
    }

MontecarloMultiProvider_thread::~MontecarloMultiProvider_thread()
    {
    // rien
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* MontecarloMultiProvider_thread::createUse(const Grid& grid , bool isVerbose)
    {
    return new MontecarloMultiUse_thread(grid, isVerbose, nbDar, h);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* MontecarloMultiProvider_thread::createUse(bool isVerbose)
    {
    return new MontecarloMultiUse_thread(isVerbose, nbDar, h);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
