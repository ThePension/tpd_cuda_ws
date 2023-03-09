#include "MontecarloMultiUse_thread.h"

#include "MontecarloUseTools.h"
#include "MontecarloMulti_thread.h"

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

MontecarloMultiUse_thread::MontecarloMultiUse_thread(const Grid& grid , bool isVerbose , entier nbDar , float h) : //
	nbDar(nbDar), //
	grid(grid), //
	piHat(-1)
    {
    this->ptrRunnableGPU = new MontecarloMulti_thread(grid, nbDar, &this->piHat, h, isVerbose);
    }

MontecarloMultiUse_thread::MontecarloMultiUse_thread(bool isVerbose , entier nbDar , float h) : //
	MontecarloMultiUse_thread(createGrid(), isVerbose, nbDar, h)
    {
    // rien
    }

/*--------------*\
|*	standard*|
 \*-------------*/

MontecarloMultiUse_thread::MontecarloMultiUse_thread(const Grid& grid , bool isVerbose) : //
	MontecarloMultiUse_thread(grid, isVerbose, MontecarloUseTools::nbDarTotalUse(), MontecarloUseTools::H)
    {
    // rien
    }

MontecarloMultiUse_thread::MontecarloMultiUse_thread(bool isVerbose , float h) : //
	MontecarloMultiUse_thread(createGrid(), isVerbose, MontecarloUseTools::nbDarTotalUse(), h)
    {
    //rien
    }

MontecarloMultiUse_thread::MontecarloMultiUse_thread(bool isVerbose) : //
	MontecarloMultiUse_thread(createGrid(), isVerbose)
    {
    //rien
    }

MontecarloMultiUse_thread::~MontecarloMultiUse_thread()
    {
    delete ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 */
bool MontecarloMultiUse_thread::filter(const Grid& grid)
    {
    return Use_I::filter(grid) //
    && Maths::isPower2(grid.threadByBlock());
    }

/*--------------*\
|*	isOk	*|
 \*-------------*/

bool MontecarloMultiUse_thread::isOk(bool isVerbose)
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
RunnableGPU_I* MontecarloMultiUse_thread::getRunnableGPU()
    {
    return ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
Grid MontecarloMultiUse_thread::createGrid()
    {
    const int MP = Hardware::getMPCount();

#ifdef DAR_INT
    dim3 dg(MP * 5, 1, 1);
    dim3 db(64, 1, 1); // power 2 reduction
    Grid grid(dg, db);

    return grid;
#endif

#ifdef DAR_LONG
    dim3 dg(MP * 2, 1, 1);
    dim3 db(512, 1, 1); // power 2 reduction
    Grid grid(dg, db);

    return grid;
#endif
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
