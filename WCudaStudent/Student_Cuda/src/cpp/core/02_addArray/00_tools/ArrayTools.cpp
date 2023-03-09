#include <iostream>
#include <math.h>

#include "ArrayTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*	Methode	public (static)		*|
 \*-------------------------------------*/

bool ArrayTools::isAddVector_Ok(float* ptrV1 , float* ptrV2 , float* ptrW , int n)
    {
    float* ptrResult = new float[n];

    addVectorCPU(ptrV1, ptrV2, ptrResult, n);
    bool isOk = isEquals(ptrResult, ptrW, n, 1e-6); // comparer version cpu (ptrResult) avec version gpu (ptrW)

    free(ptrResult);

    return isOk;
    }

/**
 * 1 2 3 4 5
 */
float* ArrayTools::createV1(int n)
    {
    float* ptrV = new float[n];

    for (int i = 0; i < n; i++)
	{
	ptrV[i] = i + 1;
	}

    return ptrV;
    }

/**
 * 10 20 30 40 50
 */
float* ArrayTools::createV2(int n)
    {
    float* ptrV = new float[n];

    for (int i = 0; i < n; i++)
	{
	ptrV[i] = (i + 1) * 10;
	}

    return ptrV;
    }

void ArrayTools::print(float* ptrV , int n)
    {
    cout << endl;
    for (int i = 0; i < n; i++)
	{
	cout << ptrV[i] << "\t";
	}
    cout << endl;
    }

/*--------------------------------------*\
 |*	Methode	private (static)	*|
 \*-------------------------------------*/

/**
 * v1,v2,w same size
 */
void ArrayTools::addVectorCPU(float* ptrV1 , float* ptrV2 , float* ptrW , int n)
    {
    for (int i = 0; i < n; i++)
	{
	ptrW[i] = ptrV1[i] + ptrV2[i];
	}
    }

/**
 * simple
 */
bool ArrayTools::isEquals(float* ptrV1 , float* ptrV2 , int n , float epsilon)
    {
    for (int i = 1; i <= n; i++)
	{
	float delta = fabs(*ptrV1 - *ptrV2);

	if (delta > epsilon)
	    {
	    return false;
	    }

	ptrV1++;
	ptrV2++;
	}

    return true;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

