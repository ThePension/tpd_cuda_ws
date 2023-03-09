#pragma once

#include "cudas.h"
#include "Grid.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/
/**
 * On passse la grille à AddScalar pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 */
class AddScalar
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * resultat dans c
	 * c=a+b
	 */
	AddScalar(float a, float b, float* ptrSum);

	virtual ~AddScalar(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void run();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float a;
	float b;

	// Inputs/Outputs
	float* ptrSum;

	// Tools
	float* ptrSumGM;
	size_t sizeFloat;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
