#pragma once

#include "cudas.h"
#include "Grid.h"
#include "RunnableGPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/


class AddArray11
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update w by v1+v2
	 */
	AddArray11(const Grid& grid , float* ptrV1 , float* ptrV2 , float* ptrW , int n);

	virtual ~AddArray11(void);

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
	float* ptrV1;
	float* ptrV2;
	int n;
	dim3 dg;
	dim3 db;

	// Inputs/Outputs
	float* ptrW;

	// Tools
	float* ptrDevV1;
	float* ptrDevV2;
	float* ptrDevW;
	size_t sizeVector; //[octet]

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
