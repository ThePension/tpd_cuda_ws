#include <iostream>
#include <assert.h>

#include "VideoSurface.h"

#include "GM.h"
#include "Hardware.h"
#include "Surface2D.h"

using std::cout;
using std::cerr;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void kSeuillage(cudaSurfaceObject_t surf2d, uchar* tabPixelGM ,uint w , uint h, uchar seuil0255);
extern __global__ void KDilatation1( uchar* tabPixelGM,cudaSurfaceObject_t surf2d , uint w , uint h );
extern __global__ void KDilatationN( uchar* tabPixelGM,cudaSurfaceObject_t surf2d , uint w , uint h,int rayon );

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

VideoSurface::VideoSurface(const Grid& gridDilatation , IteratorImageGray_I* ptrIteratorImage , uchar seuil0255) :
	Animable_I<uchar>(gridDilatation, ptrIteratorImage->getW(), ptrIteratorImage->getH(), "Video_surface_uchar"), //
	//
	seuil0255(seuil0255),	//
	//
	ptrIteratorImage(ptrIteratorImage),	//
	//
	gridSeuillageBest(bestGridSeuillage()), //
	//
	wh(ptrIteratorImage->getWH()),	//
	//
	surface2d(ptrIteratorImage->getW(), ptrIteratorImage->getH(), CudaArrayType::SURFACE_LOAD_STORE)
    {
    // Tools
    this->t = 0;  // protected dans Animable

    this->sizeImage = sizeof(uchar) * wh;

    //video
	{
	this->tabPixelVideo = ptrIteratorImage->first();
	}
    }

VideoSurface::~VideoSurface()
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
 * Note : domaineMath pas use car pas zoomable
 */
void VideoSurface::process(uchar* tabPixelsGM , uint w , uint h , const DomaineMath& domaineMath)
    {
    // 1) copier tabPixelVideo dans tabPixelsGM
    // 2) seuillage
    // 3) dilatation

    // TODO
    }

/**
 * Override
 * Call periodicly by the API
 */
void VideoSurface::animationStep()
    {
    t++;

    this->tabPixelVideo = ptrIteratorImage->next();
    }

/*-------------------------*\
 |*	static		    *|
 \*-------------------------*/

Grid VideoSurface::bestGridSeuillage()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    // TODO
    assert(false);

    Grid gridConstrastor;

    return gridConstrastor;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

