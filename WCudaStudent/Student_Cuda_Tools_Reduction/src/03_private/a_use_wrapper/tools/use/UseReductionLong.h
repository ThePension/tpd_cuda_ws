#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"

#include "PLong.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class UseReductionLong: public Use_I
    {
	/*------------------------------------------------------------*\
        |*			Constructors 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * db power 2
	 */
	UseReductionLong(const Grid& grid , bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PLong* ptrPlong);

	UseReductionLong(bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PLong* ptrPlong);

	virtual ~UseReductionLong();

	/*------------------------------------------------------------*\
	|*			virtual 			      *|
	 \*------------------------------------------------------------*/

	/*------------------------------------------------------------*\
        |*			Methodes 			      *|
	 \*------------------------------------------------------------*/

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

    protected:

	static Grid createGrid(const PLong& plong);

	/*------------------------------------------------------------*\
        |*			Attributs			      *|
	 \*------------------------------------------------------------*/

    private:

	// Input
	Grid grid;
	PLong* ptrPlong;

	// Input/Output
	RunnableGPU_I* ptrRunnableGPU;

    protected:

	// Tools
	long sum;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
