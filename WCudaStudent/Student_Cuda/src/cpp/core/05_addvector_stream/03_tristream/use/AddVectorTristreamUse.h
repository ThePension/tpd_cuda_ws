#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"
#include "cuda_fp16.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class AddVectorTristreamUse: public Use_I
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * nbSlice in [3,12]
	 */
	AddVectorTristreamUse(const Grid& grid , int nbSlice , bool isVerbose);

	/**
	 * nbSlice in [3,12]
	 */
	AddVectorTristreamUse(int nbSlice , bool isVerbose);

	virtual ~ AddVectorTristreamUse();

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

    public:

	static int nbSliceOptimum();

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
