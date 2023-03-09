#pragma once

#include "Use_I.h"
#include "Grid.h"
#include "RunnableGPU_I.h"
#include "entier.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class MontecarloMultiUse_thread: public Use_I
    {
	/*------------------------------------------------------------*\
        |*			Constructors 			      *|
	 \*------------------------------------------------------------*/

	 public:

	/*--------------*\
	|* Tests	*|
	 \*-------------*/

	/**
	 * db power 2
	 */
	MontecarloMultiUse_thread(const Grid& grid , bool isVerbose , entier nbDar , float h);


	MontecarloMultiUse_thread(bool isVerbose , entier nbDar , float h);


	/*--------------*\
		|* standard	*|
		 \*-------------*/

    public:

	/**
	 * db power 2
	 */
	MontecarloMultiUse_thread(const Grid& grid,bool isVerbose);

	MontecarloMultiUse_thread(bool isVerbose);

	MontecarloMultiUse_thread(bool isVerbose,float h);

	virtual ~MontecarloMultiUse_thread();

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
	entier nbDar;
	Grid grid;

	// Tools
	double piHat;

	// Output
	RunnableGPU_I* ptrRunnableGPU;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
