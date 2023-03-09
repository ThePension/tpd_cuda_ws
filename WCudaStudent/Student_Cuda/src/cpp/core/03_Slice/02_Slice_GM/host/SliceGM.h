#pragma once

#include "cudas.h"
#include "Grid.h"
#include "RunnableGPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/


class SliceGM: public RunnableGPU
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update piHat
	 * Hyp : nbThread est une puissance de 2
	 */
	SliceGM(Grid grid , int nbSlice , double* ptrPiHat , bool isVerbose);

	virtual ~SliceGM();

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * override
	 */
	virtual void run();

    private:

	void reductionGM();


	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int nbSlice;

	// Inputs/Outputs
	double* ptrPiHat;

	// Tools
	float* tabGM;
	size_t sizeTabGM; // [octet]
	int nTabGM;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
