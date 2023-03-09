#include "MontecarloProvider.h"

#include "MontecarloUse.h"
#include "MontecarloUseTools.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

MontecarloProvider::MontecarloProvider(float h,entier nbDar) ://
	h(h),//
	nbDar(nbDar)
    {
    // rien
    }

MontecarloProvider::MontecarloProvider()://
	MontecarloProvider(MontecarloUseTools::H,MontecarloUseTools::nbDarTotalUse())
    {
    // rien
    }



MontecarloProvider::~MontecarloProvider()
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
Use_I* MontecarloProvider::createUse(const Grid& grid , bool isVerbose)
    {
    return new MontecarloUse(grid, isVerbose,nbDar,h);
    }

/**
 * override
 * Mandatory : delete yourself UseGPU_I*
 */
Use_I* MontecarloProvider::createUse(bool isVerbose)
    {
    return new MontecarloUse(isVerbose,nbDar,h);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
