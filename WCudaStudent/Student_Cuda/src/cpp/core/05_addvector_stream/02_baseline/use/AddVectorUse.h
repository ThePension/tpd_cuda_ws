#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"


/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class AddVectorUse: public Use_I
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	AddVectorUse(const Grid& grid ,bool isVerbose);

	AddVectorUse(bool isVerbose);

	virtual ~ AddVectorUse();

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
