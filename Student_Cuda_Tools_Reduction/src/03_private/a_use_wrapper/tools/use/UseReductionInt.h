#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"

#include "PInt.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class UseReductionInt: public Use_I
    {
	/*------------------------------------------------------------*\
        |*			Constructors 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * db power 2
	 */
	UseReductionInt(const Grid& grid , bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PInt* ptrPint);

	UseReductionInt(bool isVerbose , RunnableGPU_I* ptrRunnableGPU , PInt* ptrPint);

	virtual ~UseReductionInt();

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

	static Grid createGrid(const PInt& pint);

	/*------------------------------------------------------------*\
        |*			Attributs			      *|
	 \*------------------------------------------------------------*/

    private:

	// Input
	Grid grid;
	PInt* ptrPint;

	// Input/Output
	RunnableGPU_I* ptrRunnableGPU;

    protected:

	// Tools
	int sum;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
