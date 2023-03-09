#include <iostream>
#include <math.h>
#include <assert.h>

#include "VectorTools.h"
#include "HM.h"
#include "Limits.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * static
 *
 * Choisir un nombre de slice tq n%nbSlice=0
 */
int VectorTools::n()
    {
    return n1();
    //return n2();

    //return nDebug();
    }

/**
 * static
 *
 * cas1 :
 * 	cas 1.a : #slice in [2,15]
 * 	cas 1.b : #slice in [5,75] par pas de 5
 *
 * Choisir un nombre de slice tq N%nbSlice=0
 */
int VectorTools::n1()
    {
    const int N = 2 * 3 * 4 * 5 * 7 * 9 * 11 * 13 * 5; // apres trop grand
    // 8  remove car 2*4
    // 10 remove car 2*5
    // 12 remove car 3*4
    // 15 remove car 3*5

    checkN1(N);

    return N;
    }

/**
 * static
 */
void VectorTools::checkN1(int N)
    {
    //cout << N << endl;

    assert(N >= 3);
    assert(N <= Limits::MAX_INT);

    for (int i = 2; i <= 15; i++)
	{
	//cout << i << endl;
	assert(N % i == 0); // pour pouvoir faire varier le nombre de slice entre [3,nbSliceMax()]
	}

    for (int i = 5; i <= 75; i += 5)
	{
	//cout << i << endl;
	assert(N % i == 0); // pour pouvoir faire varier le nombre de slice par pas de 5 dans [0,60]
	}
    }

/**
 * static
 *
 * cas 2  :
 * 	Possibility a : #slice  10 20 30 40 50
 * 	Possibility b : #slice  10 100 1000 10000 20000 30000 40000 50000
 *
 * Choisir un nombre de slice tq N%nbSlice=0
 */
int VectorTools::n2()
    {
    const int N = 2 * 3 * 4 * 5 * 10 * 10 * 10 * 10 * 2;
    return N;
    }

/**
 * static
 *
 * Choisir un nombre de slice tq N%nbSlice=0
 */
int VectorTools::nDebug()
    {
    //const int N=6;	// debug use only 3 slice
    //const int N=8;	// debug use only 4 slice
    //const int N=10;	// debug use only 5 slice
    const int N = 6;

    return N;
    }

/*--------------------------------------*\
 |*		MM			*|
 \*-------------------------------------*/

static bool IS_MEMORY_DMA = true;

bool VectorTools::isDMA()
    {
    return IS_MEMORY_DMA;
    }

int* VectorTools::create(int n)
    {
    if (!IS_MEMORY_DMA)
	{
	return new int[n];
	}
    else
	{
	int* ptr;
	HM::malloc(&ptr, n * sizeof(int));
	return ptr;
	}
    }

void VectorTools::free(int* ptrV)
    {
    if (!IS_MEMORY_DMA)
	{
	delete[] ptrV;
	}
    else
	{
	HM::free(ptrV);
	}
    }

/*--------------------------------------*\
 |*	Methode	public (static)		*|
 \*-------------------------------------*/

bool VectorTools::isAddVector_Ok(int* ptrV1 , int* ptrV2 , int* ptrW , int n)
    {
    for (int i = 0; i < n; i++)
	{
	int delta=ptrW[i]-ptrV1[i]-ptrV2[i];

	if (delta !=0)
	    {
	    return false;
	    }
	}

    return true;
    }

int* VectorTools::createV1(int n)
    {
    int* ptrV = VectorTools::create(n);

    for (int i = 0; i < n; i++)
	{
	ptrV[i] = i;
	}

    return ptrV;
    }

int* VectorTools::createV2(int n)
    {
    int* ptrV = VectorTools::create(n);

    for (int i = 0; i < n; i++)
	{
	ptrV[i] = i * 10;
	}

    return ptrV;
    }

void VectorTools::print(int* ptrV , int n)
    {
    cout << endl;
    for (int i = 0; i < n; i++)
	{
	cout << ptrV[i] << "\t";
	}
    cout << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

