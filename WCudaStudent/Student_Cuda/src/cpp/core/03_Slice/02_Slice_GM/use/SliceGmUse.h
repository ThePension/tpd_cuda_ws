#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class SliceGmUse: public Use_I
    {
	/*------------------------------------------------------------*\
        |*			Constructors 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * contrainte : grid (dg et db) une puissance de 2, pour etre compatible avec SLICE_GM_PLUS
	 */
	SliceGmUse(const Grid& grid,bool isVerbose);

	SliceGmUse(bool isVerbose);

	virtual ~SliceGmUse();

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
