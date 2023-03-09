#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"
#include "cuda_fp16.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class AddVectorBistreamUse: public Use_I
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	AddVectorBistreamUse(const Grid& grid ,bool isVerbose);

	AddVectorBistreamUse(bool isVerbose);

	virtual ~ AddVectorBistreamUse();

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * override
	 * Warning : It's a getter, the user is not responsible for deleting RunnableGPU_I*
	 */
	RunnableGPU_I* getRunnableGPU();

	/**
	 * override
	 */
	bool isOk(bool isVerbose = false);

	/**
	 * override
	 */
	bool filter(const Grid& grid);

	int getN();

    protected:

	static Grid createGrid();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	//Inputs
	Grid grid;
	int n;

	// Tools
	int* ptrV1;
	int* ptrV2;
	int* ptrW;

	// Output
	RunnableGPU_I* ptrRunnableGPU;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
