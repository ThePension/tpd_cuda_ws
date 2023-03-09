#include "MontecarloMulti_thread.h"

#include <iostream>
#include <assert.h>

#include "Montecarlo.h"
#include "Hardware.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * static
 */
int MontecarloMulti_thread::NB_DEVICE = Hardware::getDeviceCount();

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

MontecarloMulti_thread::MontecarloMulti_thread(const Grid& grid , entier nbDarTotalAsk , double* ptrPiHat , float h , bool isVerbose) :
	RunnableGPU(grid, title(nbDarTotalAsk, h), isVerbose), // classe parente
//
	nbDarTotalAsk(nbDarTotalAsk), //
	ptrPiHat(ptrPiHat), //
	h(h), //
	grid(grid)
    {
    this->nbDarByDevice = -1; // TODO MontecarloMulti-thread
    assert(nbDarByDevice >= grid.threadCounts());

    // warning
	{
	// TODO MontecarloMulti : Charger les drivers de tous les gpus avec:
	//
	//		Hardware::loadCudaDriverAll();
	//
	// sinon votre code multi gpu sera sequentiel!
	// Le mieux est de faire ca dans main.cpp avec la directive
	//
	// 	DeviceDriver::LOAD_ALL;
	}
    }

MontecarloMulti_thread::~MontecarloMulti_thread()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void MontecarloMulti_thread::run()
    {
    const int DEVICE_ID_ORIGINAL = Hardware::getDeviceId();

    this->nbDarTotalEffective = 0;
    entier nbDarUnderCurve = 0;

    // paraleliser la boucle avec OpenMP (regarder le dernier exemple o8 OMP de slice,)
    for (int deviceID = 0; deviceID < NB_DEVICE; ++deviceID)
	{
	// TODO MontecarloMulti-thread : utiliser Montecarlo

	// Version parallel:
	//
	//   (P1) Il y a deux reductions à faire:
	//			nbDarTotalEffective
	//			nbDarUnderCurve
	//
	//   (P2) Utiliser une section critique! C'est pas cher, pas beaucoup de GPU, pas beaucoup de threads host-side!
	//
	//		#pragma omp critical(blabla)
	//			{
	//			...
	//			}
	}

    // TODO MontecarloMulti-thread
    // calculer piHat avec nbDarTotalEffective et nbDarUnderCurve
    *this->ptrPiHat = -1;

    Hardware::setDevice(DEVICE_ID_ORIGINAL); // on restore le device d'origine

    // Truc:
    //
    // 		Faite fonctionner ce code multiGPU d'abord "sequentiel", Device after Device, puis seulement ensuite tous les GPU en paralell
    // 		Utiliser en ligne de commande
    //
    //			nvidia-smi --loop=1
    //
    // 		pour voir le 100% d'utilisation du device, changer de device en device dans le cas sequentiel, puis voir un 100% simultaner sur tous les devices en meme temps
    // 		Tirer assez de flechette (cas long) pour avoir le temps de monitorer (cf entier.h du to Montecarlo).
    //
    // 		Une fois l'observation terminer, kitter nvidia-smi (CTRL-C)
    //
    // Observation:
    //
    //		(O1) En int, les performances ne sont pas a la hauteur des esperances
    //		     Pire, c est meme parfois moins bon qu en mono gpu
    //
    //		(O2) En long, les performances sont a la hauteur des espoirs.
    //		     ie environ NB_DEVICE plus rapide que la version mono GPU
    //
    //	Explication:
    //
    //		En int, les kernels sont tres courts. La creation des threads cote host coute trop cher!
    //		En long, la creation des threads n est pas plus rapide, mais ce temps de creation devient negligeable par rapport a la durre des kernels
    //
    //	Conseil:
    //
    //		Realiser la version avec les streams au lieu des threads.
    //		En int, comme en long, les performances seront au top!
    //		C est a peine plus difficile que les threads!
    }

/*----------------*\
 |*	get        *|
 \*---------------*/

entier MontecarloMulti_thread::getNbDarTotalEffective()
    {
    return nbDarTotalEffective;
    }

double MontecarloMulti_thread::getInputGO()
    {
    return (nbDarTotalEffective / (double)1024 / (double)1024 / (double)1024) * sizeof(float) * 2;
    }

/*----------------*\
 |*	set        *|
 \*---------------*/

void MontecarloMulti_thread::setH(float h)
    {
    this->h = h;
    }

/*----------------*\
 |*  private       *|
 \*---------------*/

string MontecarloMulti_thread::title(entier nbDarTotalAsk , float h)
    {
    return "MontecarloMulti-thread-" + entierToString() + "-" + to_string(nbDarTotalAsk) + "-h" + to_string((int)h);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
