#include "MontecarloMultiUse_stream.h"

#include "MontecarloUseTools.h"
#include "MontecarloMulti_stream.h"

#include "Maths.h"
#include "Hardware.h"
#include "ChronoFactory.h"

#include <iostream>
#include <iomanip>
#include <assert.h>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::setprecision;

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

/*--------------*\
|*	test*|
 \*-------------*/

MontecarloMultiUse_stream::MontecarloMultiUse_stream(const Grid& grid , bool isVerbose , entier nbDar , float h) : //
	nbDar(nbDar), //
	grid(grid), //
	piHat(-1)
    {
    //this->ptrRunnableGPU = new MontecarloMulti(grid, nbDar, &this->piHat, h, isVerbose);
    this->ptrRunnableGPU = new MontecarloMulti_stream(grid, nbDar, &this->piHat, h, isVerbose);
    }

MontecarloMultiUse_stream::MontecarloMultiUse_stream(bool isVerbose , entier nbDar , float h) : //
	MontecarloMultiUse_stream(createGrid(), isVerbose, nbDar, h)
    {
    // rien
    }

/*--------------*\
|*	standard*|
 \*-------------*/

MontecarloMultiUse_stream::MontecarloMultiUse_stream(const Grid& grid , bool isVerbose) : //
	MontecarloMultiUse_stream(grid, isVerbose, MontecarloUseTools::nbDarTotalUse(), MontecarloUseTools::H)
    {
    // rien
    }

MontecarloMultiUse_stream::MontecarloMultiUse_stream(bool isVerbose , float h) : //
	MontecarloMultiUse_stream(createGrid(), isVerbose, MontecarloUseTools::nbDarTotalUse(), h)
    {
    //rien
    }

MontecarloMultiUse_stream::MontecarloMultiUse_stream(bool isVerbose) : //
	MontecarloMultiUse_stream(createGrid(), isVerbose)
    {
    //rien
    }

MontecarloMultiUse_stream::~MontecarloMultiUse_stream()
    {
    delete ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 */
bool MontecarloMultiUse_stream::filter(const Grid& grid)
    {
    return Use_I::filter(grid) //
    && Maths::isPower2(grid.threadByBlock());
    }

/*--------------*\
|*	isOk	*|
 \*-------------*/

bool MontecarloMultiUse_stream::isOk(bool isVerbose)
    {
    bool isOk = true;

    Chrono* ptrChrono = ChronoFactory::create();
    ptrRunnableGPU->run();
    ptrChrono->stop();

    isOk &= Maths::isEquals(this->piHat, PI, 1e-3);

    if (isVerbose)
	{
	string title = "[" + ptrRunnableGPU->getTitle() + "]";
	cout << endl << title;

	MontecarloUseTools::performance(ptrChrono->getElapseTimeS(), nbDar, isOk);
	}

    delete ptrChrono;

    return isOk;
    }

/*--------------*\
|*	get	*|
 \*-------------*/

/**
 * override
 * Warning : It's a getter, the user is not responsible for deleting RunnableGPU_I*
 */
RunnableGPU_I* MontecarloMultiUse_stream::getRunnableGPU()
    {
    return ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
Grid MontecarloMultiUse_stream::createGrid()
    {
    const int MP = Hardware::getMPCount();

    // Merci de ne pas lancer de brute force pour ce TP (fais souvent planter le GPU)
    // Voila ma meilleur grid

#ifdef DAR_INT
    dim3 dg(MP, 1, 1);
    dim3 db(1024, 1, 1); // power 2 reduction
    Grid grid(dg, db);

    return grid;
#endif

#ifdef DAR_LONG	// pas tuner, bruteforce plante gpu
    dim3 dg(MP , 1, 1);
    dim3 db(1024, 1, 1); // power 2 reduction
    Grid grid(dg, db);

    return grid;
#endif
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
