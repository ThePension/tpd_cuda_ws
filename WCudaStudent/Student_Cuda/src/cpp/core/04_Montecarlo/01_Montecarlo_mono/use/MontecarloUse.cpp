#include "MontecarloUse.h"

#include "Montecarlo.h"
#include "MontecarloUseTools.h"

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

MontecarloUse::MontecarloUse(const Grid& grid , bool isVerbose , entier nbDar , float h) : //
	nbDar(nbDar), //
	grid(grid), //
	piHat(-1)
    {
    this->ptrRunnableGPU = new Montecarlo(grid, nbDar, &this->piHat, h, isVerbose);
    }

MontecarloUse::MontecarloUse(bool isVerbose , entier nbDar , float h) : //
	MontecarloUse(createGrid(), isVerbose, nbDar, h)
    {
    // rien
    }

/*--------------*\
|*	standard*|
 \*-------------*/

MontecarloUse::MontecarloUse(const Grid& grid , bool isVerbose) : //
	MontecarloUse(grid, isVerbose, MontecarloUseTools::nbDarTotalUse(), MontecarloUseTools::H)
    {
    // rien
    }

MontecarloUse::MontecarloUse(bool isVerbose , float h) : //
	MontecarloUse(createGrid(), isVerbose, MontecarloUseTools::nbDarTotalUse(), h)
    {
    //rien
    }

MontecarloUse::MontecarloUse(bool isVerbose) : //
	MontecarloUse(createGrid(), isVerbose)
    {
    //rien
    }

MontecarloUse::~MontecarloUse()
    {
    delete ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 */
bool MontecarloUse::filter(const Grid& grid)
    {
    return Use_I::filter(grid) //
    && Maths::isPower2(grid.threadByBlock());
    }

/*--------------*\
|*	isOk	*|
 \*-------------*/

bool MontecarloUse::isOk(bool isVerbose)
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
RunnableGPU_I* MontecarloUse::getRunnableGPU()
    {
    return ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		private			*|
 \*-------------------------------------*/

/**
 * static
 */
Grid MontecarloUse::createGrid()
    {
    const int MP = Hardware::getMPCount();

    // Contraintes :
    //	(C1) max(db.x*db.y*db.z)<=1024
    //	(C2) db power 2 (reduction)

#ifdef DAR_INT

    Grid grid; // TODO Montecarlo
    assert(false); // to remove once coded

    return grid;
#endif

#ifdef DAR_LONG

    Grid grid; // TODO Montecarlo
     assert(false); // to remove once coded

    return grid;
#endif
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
