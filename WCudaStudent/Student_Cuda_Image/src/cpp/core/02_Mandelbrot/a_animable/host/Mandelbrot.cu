#include "Mandelbrot.h"

#include <iostream>
#include <assert.h>

#include "Hardware.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void mandelbrot(uchar4* tabPixelsGM, uint w, uint h,DomaineMath domaineMath, int n);

/*--------------------------------------*\
 |*		private		 	*|
 \*-------------------------------------*/

static string titre();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Mandelbrot::Mandelbrot(const Grid& grid , uint w , uint h , const DomaineMath& domaineMath ,bool isVerbose, int nMin , int nMax) :
	Animable_I<uchar4>(grid, w, h, titre(), domaineMath,isVerbose), // super classe
	variateurT(Interval<int>(nMin, nMax), 1), // tools animation
	nMin(nMin), // Inputs animation
	nMax(nMax) // Inputs animation
    {
    // Tools
    this->t = nMin;
    }

Mandelbrot::~Mandelbrot()
    {
    // rien
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 */
void Mandelbrot::process(uchar4* tabPixelsGM , uint w , uint h , const DomaineMath& domaineMath)
    {
    int n = t;

    assert(false); // to be removed once implemented
    // TODO Mandelbrot GPU
    // lauch kernel (line 18)
    }

/**
 * Override
 * Call periodicly by the API
 */
void Mandelbrot::animationStep()
    {
    this->t = variateurT.varierAndGet();
    }

string titre()
    {
    return "Mandelbrot-Cuda-uchar4-" + realToString();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

