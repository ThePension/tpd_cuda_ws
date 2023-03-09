#include "AddArray.h"

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

extern __global__ void addArray(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

AddArray::AddArray(const Grid& grid , float* ptrV1 , float* ptrV2 , float* ptrW , int n) :
	ptrV1(ptrV1), //
	ptrV2(ptrV2), //
	ptrW(ptrW), //
	n(n), //
	dg(grid.dg), //
	db(grid.db)
    {
    this->sizeVector = n * sizeof(float);

    // MM (malloc Device)
	{
	GM::malloc(&ptrDevV1, sizeVector);
	GM::malloc(&ptrDevV2, sizeVector);
	GM::malloc(&ptrDevW, sizeVector);
	}

    }

AddArray::~AddArray(void)
    {
    //MM (device free)
	{
	GM::free(ptrDevV1);
	GM::free(ptrDevV2);
	GM::free(ptrDevW);
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * override
 */
void AddArray::run()
    {
    // MM (copy Host->Device)
	{
	GM::memcpyHToD(ptrDevV1, ptrV1, sizeVector);
	GM::memcpyHToD(ptrDevV2, ptrV2, sizeVector);
	}

	addArray<<<dg, db>>>(ptrDevV1, ptrDevV2, ptrDevW, n);

    //Kernel::synchronize();// inutile

    // MM (Device -> Host)
	{
	GM::memcpyDToH(ptrW, ptrDevW, sizeVector);
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
