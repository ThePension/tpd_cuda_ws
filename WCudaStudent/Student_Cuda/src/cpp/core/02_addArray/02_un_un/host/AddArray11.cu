#include "AddArray11.h"

#include <iostream>
#include <assert.h>

#include "Kernel.h"
#include "GM.h"
#include "VectorTools.h"

using std::cout;
using std::endl;
using std::to_string;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void addArray11(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

AddArray11::AddArray11(const Grid& grid , float* ptrV1 , float* ptrV2 , float* ptrW , int n) :
	ptrV1(ptrV1), //
	ptrV2(ptrV2), //
	ptrW(ptrW), //
	n(n), //
	dg(grid.dg), //
	db(grid.db)
    {
    this->sizeVector = -1; // TODO addArray11 // octet

    // MM (malloc Device)
	{
	// TODO addArray11
	}
    }

AddArray11::~AddArray11(void)
    {
    //MM (device free)
	{
	// TODO addArray11
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * override
 */
void AddArray11::run()
    {
    // MM (copy Host->Device)
	{
	// TODO addArray11
	}

    assert(dg.x * dg.y * dg.z * db.x * db.y * db.z == n);
    // TODO addArray11 call kernel

    // MM (Device -> Host)
	{
	// TODO addArray11
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
