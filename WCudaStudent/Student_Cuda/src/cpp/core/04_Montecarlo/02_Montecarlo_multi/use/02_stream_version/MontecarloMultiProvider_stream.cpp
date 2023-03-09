#include "MontecarloMultiProvider_stream.h"

#include "MontecarloMultiUse_stream.h"
#include "MontecarloUseTools.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

MontecarloMultiProvider_stream::MontecarloMultiProvider_stream(float h , entier nbDar) : //
	h(h), //
	nbDar(nbDar)
    {
    // rien
    }

MontecarloMultiProvider_stream::MontecarloMultiProvider_stream() : //
	MontecarloMultiProvider_stream(MontecarloUseTools::H, MontecarloUseTools::nbDarTotalUse())
    {
    // rien
    }

MontecarloMultiProvider_stream::~MontecarloMultiProvider_stream()
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
Use_I* MontecarloMultiProvider_stream::createUse(const Grid& grid , bool isVerbose)
    {
    return new MontecarloMultiUse_stream(grid, isVerbose, nbDar, h);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* MontecarloMultiProvider_stream::createUse(bool isVerbose)
    {
    return new MontecarloMultiUse_stream(isVerbose, nbDar, h);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
