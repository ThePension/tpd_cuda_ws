#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class SliceGmHostUse: public Use_I
    {
	/*------------------------------------------------------------*\
        |*			Constructors 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * contrainte : dg power 2
	 */
	SliceGmHostUse(const Grid& grid,bool isVerbose);

	SliceGmHostUse(bool isVerbose);

	virtual ~SliceGmHostUse();

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

    private:

	static Grid createGrid();

	/*------------------------------------------------------------*\
        |*			Attributs			      *|
	 \*------------------------------------------------------------*/

    private:

	// Input
	int nbSlice;
	Grid grid;

	// Tools
	double piHat;

	// Output
	RunnableGPU_I* ptrRunnableGPU;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
