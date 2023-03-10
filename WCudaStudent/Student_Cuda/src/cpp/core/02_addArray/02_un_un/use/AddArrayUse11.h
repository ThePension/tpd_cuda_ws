#pragma once

#include "Grid.h"
#include "AddArray11.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class AddArrayUse11
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	AddArrayUse11();

	virtual ~AddArrayUse11();

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	bool isOk();

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
	float* ptrV1;
	float* ptrV2;
	float* ptrW;

	// Output
	AddArray11* ptrAddArray11;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
