#include "Montecarlo.h"

#include <iostream>
#include <assert.h>
#include <typeinfo>
#include <math.h>

#include "GM.h"
#include "Hardware.h"
#include "Stream.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void createGenerator(curandState* tabGeneratorGM,int deviceId);

extern __global__ void montecarlo(curandState* tabGeneratorGM, entier nbDarByThread, entier* ptrNbDarUnderGM, float h);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

Montecarlo::Montecarlo(const Grid& grid , entier nbDarTotalAsk , double* ptrPiHat , float h , bool isVerbose) :
	RunnableGPU(grid, title(nbDarTotalAsk, h), isVerbose), // classe parente
	//
	nbDarTotalAsk(nbDarTotalAsk), //
	ptrPiHat(ptrPiHat), //
	h(h) //

    {
    const entier NB_THREAD = grid.threadCounts(); //directement en entier pour éviter un cast

    // Math : Calculer le nombre de flechette effectivment tirer!
	{
	this->nbDarByThread = -1; //TODO Montecarlo
	this->nbDarTotalEffective = -1; // TODO Montecarlo

	assert(nbDarTotalAsk >= grid.threadCounts());
	assert(nbDarByThread > 0); // si =0, trop de threads et pas assez de dar!
	}

    // MM
	{
	this->sizeNbDarUnderGM = -1; // [octet]

	// TODO Montecarlo MM NbDarUnderGM (pas oublier de mettre a zero, avec un malloc0 par exemple)

	this->sizeSM = -1; // [octet]
	}

    // init : lancer le kernel de creation des generators
	{
	size_t sizeTabDevGeneratorGM = -1; // TODO Montecarlo

	// TODO Montecarlo MM pou  tabDevGeneratorGM

	// TODO Montecarlo lancer le kernel createGenerator
	int deviceId = Hardware::getDeviceId();

	}
    }

Montecarlo::~Montecarlo(void)
    {
//MM (device free)
	{
	// TODO Montecarlo MM
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Lancer kernel
 * Recuperer resultat coter host
 * Finaliser le calcul de pi
 */
void Montecarlo::run()
    {
    // Version :  mono pure
	{
	// TODO Montecarlo

	}

    // Version : compatible with multiGPU, stream-version
	{
	// rien pour version mono pure
	// puis des la version MontecarloMulti-stream
	// commenter la version ci-dessus, et utiliser :
	//	- kernel_async
	//	- DtoH_async
	//	- Stream::synchronize(0);
	// Valider cette npuvelle version, d'abord en reexecutamt une Montecarlo(Mono)
	// TODO Montecarlo MontecarloMulti-stream
	}

    // calcule de Math
    // TODO Montecarlo
    }

/*----------------*\
 |*	get        *|
 \*---------------*/

entier Montecarlo::getNbDarTotalEffective()
    {
    return nbDarTotalEffective;
    }

entier Montecarlo::getNbDarUnderCurve()
    {
    return nbDarUnderCurve;
    }

double Montecarlo::getInputGO()
    {
    return (nbDarTotalEffective / (double)1024 / (double)1024 / (double)1024) * sizeof(float) * 2;
    }

/*----------------*\
 |*  private       *|
 \*---------------*/

/**
 * static
 */
string Montecarlo::title(entier nbDarTotalAsk , float h)
    {
    return "Montecarlo-" + entierToString() + "-" + to_string(nbDarTotalAsk) + "-h" + to_string((int)h);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
