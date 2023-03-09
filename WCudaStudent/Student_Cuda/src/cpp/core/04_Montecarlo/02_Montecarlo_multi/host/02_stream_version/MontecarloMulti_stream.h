#pragma once

#include <curand_kernel.h>

#include "cudas.h"
#include "Grid.h"
#include "entier.h"
#include "RunnableGPU.h"
#include "Montecarlo.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * On passse la grille à MontecarloMulti pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 */
class MontecarloMulti_stream: public RunnableGPU
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update piHat
	 * Hyp : nbThread est une puissance de 2
	 */
	MontecarloMulti_stream(const Grid& grid , entier nbDarTotalAsk , double* ptrPiHat , float h , bool isVerbose);

	virtual ~MontecarloMulti_stream(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * override
	 */
	virtual void run();

	/**
	 * override
	 */
	virtual double getInputGO();

	/**
	 * #dar effectivement tirer
	 */
	entier getNbDarTotalEffective();

	void setH(float h);

    private:

	std::string title(entier nbDarTotalAsk , float h);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	entier nbDarTotalAsk;
	float h;

	// Inputs/Outputs
	double* ptrPiHat;

	// Tools
	entier nbDarTotalEffective;

	entier nbDarByDevice;
	Grid grid;

	// Toosl : multigpu
	cudaStream_t* tabStream;
	Montecarlo** tabMontecarlo;


	static int NB_DEVICE;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
