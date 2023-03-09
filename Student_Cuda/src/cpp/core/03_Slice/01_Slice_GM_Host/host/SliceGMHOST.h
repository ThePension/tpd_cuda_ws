#pragma once

#include "cudas.h"
#include "Grid.h"
#include "RunnableGPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * On passse la grille à SliceGM pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 */
class SliceGMHOST: public RunnableGPU
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update piHat
	 * Hyp : nbThread est une puissance de 2
	 */
	SliceGMHOST(Grid grid , int nbSlice , double* ptrPiHat , bool isVerbose);

	virtual ~SliceGMHOST();

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * override
	 */
	virtual void run();

    private:

	void reductionHost();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int nbSlice;

	// Inputs/Outputs
	double* ptrPiHat;

	// Tools
	float* tabGM; // promotion de tabeau en GM (GM = Global Memory du Device).
		      // On devrait presque l'appeler ptrDevTabGM, mais un tableau est deja un pointeur (sur la premiere case)
		      // et GM et est la global memory du device
		      // Terminologie: on enleve ptrDev, car redondant!
	size_t sizeTabGM; // [octet]
	int nTabGM;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
