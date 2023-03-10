#include "Rippling.h"

#include <iostream>
#include <assert.h>


#include <assert.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void rippling(uchar4* tabPixelsGM,uint w, uint h,float t);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Rippling::Rippling(const Grid& grid, uint w, uint h, float dt,bool isVerbose) :
	Animable_I<uchar4>(grid, w, h, "Rippling-Cuda-uchar4",isVerbose)// super classe
    {
    assert(w == h); // specific rippling

    // Animation
    this->dt = dt;
    this->t = 0; // protected dans Animable
    }

Rippling::~Rippling()
    {
    // rien
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car image pas zoomable
 */
void Rippling::process(uchar4* tabPixelsGM, uint w, uint h, const DomaineMath& domaineMath)
    {
    // TODO Rippling GPU
    // lancer le kernel avec <<<dg,db>>>
    // le kernel est importer ci-dessus (ligne 19)

    assert(false);// to delete once implement
    }

/**
 * Override
 * Call periodicly by the API
 */
void Rippling::animationStep()
    {
    t += dt;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

