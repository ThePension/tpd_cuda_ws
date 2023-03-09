#pragma once

#include "cudas.h"
#include "Grid.h"
#include "RunnableGPU.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class AddVectorBistream: public RunnableGPU
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update w by v1+v2
	 */
	AddVectorBistream(const Grid& grid , int* ptrV1 , int* ptrV2 , int* ptrW , int n , bool isVerbose);

	virtual ~AddVectorBistream(void);

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
	virtual double getOutputGO();

	/**
	 * override
	 */
	virtual double getInputGO();

    private:

	std::string title();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int* ptrV1;
	int* ptrV2;
	int n;

	// Inputs/Outputs
	int* ptrW;

	// Tools
	int* ptrDevV1;
	int* ptrDevV2;
	int* ptrDevW;
	size_t sizeVector; //[octet]

	cudaStream_t stream0;
	cudaStream_t stream1;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
