#include "AddVector.h"

#include <iostream>
#include <assert.h>

#include "Kernel.h"
#include "GM.h"
#include "Bandwidth.h"
#include "VectorTools.h"
#include "Stream.h"

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

extern __global__ void addVector(int* ptrDevV1, int* ptrDevV2, int* ptrDevW,int n,int sOffset=0);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

AddVector::AddVector(const Grid& grid , int* ptrV1 , int* ptrV2 , int* ptrW , int n , bool isVerbose) :
	RunnableGPU(grid, title() + "-" + to_string(n), isVerbose), // classe parente
	//
	ptrV1(ptrV1), //
	ptrV2(ptrV2), //
	ptrW(ptrW), //
	n(n)
    {
    this->sizeVector = n * sizeof(int); // octet

    // MM (malloc Device)
	{
	GM::malloc(&ptrDevV1, sizeVector);
	GM::malloc(&ptrDevV2, sizeVector);
	GM::malloc(&ptrDevW, sizeVector);
	}

    }

AddVector::~AddVector(void)
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
void AddVector::run()
    {
    // MM (copy Host->Device)
	{
	Bandwidth bandwidth(sizeVector * 2, "[" + title() + "] : Host -> GM :");

	GM::memcpyHToD(ptrDevV1, ptrV1, sizeVector);
	GM::memcpyHToD(ptrDevV2, ptrV2, sizeVector);

	if (isVerbose) // dans Runable ou RunnableGPU
	    {
	    cout << bandwidth << endl;
	    }
	}

    addVector<<<dg,db>>>(ptrDevV1, ptrDevV2, ptrDevW, n);	// assynchrone

    // MM (Device -> Host)
	{
	Bandwidth bandwidth(sizeVector, "[" + title() + "] : GM -> Host :");

	GM::memcpyDToH(ptrW, ptrDevW, sizeVector);

	if (isVerbose)
	    {
	    cout << bandwidth << endl;
	    }
	}
    }

/**
 * override
 */
double AddVector::getInputGO()
    {
    return ((long)2 * (long)n * (long)sizeof(half)) / (double)((long)1024 * (long)1024 * (long)1024);
    }

/**
 * override
 */
double AddVector::getOutputGO()
    {
    return ((long)1 * (long)n * (long)sizeof(half)) / (double)((long)1024 * (long)1024 * (long)1024);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

string AddVector::title()
    {
    if (VectorTools::isDMA())
	{
	return "Addvector-DMA-int";
	}
    else
	{
	return "Addvector-int";
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
