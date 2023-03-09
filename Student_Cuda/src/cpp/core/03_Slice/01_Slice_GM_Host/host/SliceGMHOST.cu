#include "SliceGMHOST.h"

#include <assert.h>
#include <GM.h>
#include <GM_MemoryManagement.h>
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void reductionIntraThreadGMHOST(float* tabGM,int nbSlice);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

SliceGMHOST::SliceGMHOST(Grid grid , int nbSlice , double* ptrPiHat , bool isVerbose) :
	RunnableGPU(grid, "SliceGM-HOST-" + to_string(nbSlice), isVerbose), // classe parente
//
	nbSlice(nbSlice), //
	ptrPiHat(ptrPiHat) //
    {
    // ntabGM
	{
	this->nTabGM = grid.threadCounts();
	}

    // MM
	{
	this->sizeTabGM = nTabGM * sizeof(float);
	GM::malloc(&tabGM, sizeTabGM);
	}
    }

SliceGMHOST::~SliceGMHOST(void)
    {
    //MM (device free)
	{
	GM::free(tabGM);
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * <pre>
 * Idea globale
 *
 *	Etape 0 : Promotion d'un tableau en GM (MemoryManagement MM)		(Dans le constructeur)
 * 	Etape 1 : Reduction intra-thread dans un tableau promu en GM
 * 	Etape 2 : Copy du tableau coter host
 * 	Etape 3 : Reduction  du tableau coter host
 * 	Etape 4 : Destruction GM						(Dans le destructeur)
 *
 * </pre>
 */
void SliceGMHOST::run()
    {
    reductionIntraThreadGMHOST<<<dg, db>>>(tabGM, nTabGM);
    reductionHost();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Reduction paralle sur cpu du tableau promu en GM, ramener coter host
 */
void SliceGMHOST::reductionHost()
    {
    float* tab = new float[sizeTabGM];
    GM::memcpyDToH(tab, tabGM, sizeTabGM);

    float sum = 0.f;

//#pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < nTabGM; i++)
	{
	sum += tab[i];
	}

    *ptrPiHat = sum / nTabGM;
    delete[] tab;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
