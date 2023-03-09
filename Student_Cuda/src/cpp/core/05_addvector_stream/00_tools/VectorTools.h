#pragma once

#include "cuda_fp16.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class VectorTools
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	static int n();

	static bool isAddVector_Ok(int* ptrV1 , int* ptrV2 , int* ptrW , int n);

	static int* createV1(int n);
	static int* createV2(int n);

	static void print(int* ptrV , int n);

	static bool isDMA();

	// MM
	static int* create(int n);
	static void free(int* ptrV);

    private:

	static int n1();
	static int n2();
	static int nDebug();

	static void checkN1(int n);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
