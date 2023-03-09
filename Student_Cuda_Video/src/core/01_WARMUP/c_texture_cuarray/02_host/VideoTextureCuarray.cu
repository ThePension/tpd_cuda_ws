#include <iostream>

#include "VideoTextureCuarray.h"
#include "Texture2D.h"

using std::cout;
using std::cerr;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/**
 * <pre>
 * source : 	tex2dVideo
 * destination :tabPixelsGM
 * </pre>
 */
extern __global__ void kContourTex(cudaTextureObject_t tex2dVideo,uchar* tabPixelsGM , uint w, uint h);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

VideoTextureCuarray::VideoTextureCuarray(const Grid& grid , IteratorImageGray_I* ptrIteratorImage) :
	Animable_I<uchar>(grid, ptrIteratorImage->getW(), ptrIteratorImage->getH(), "Video_contour_Texture_cuarray_uchar"), //
	//
	ptrIteratorImage(ptrIteratorImage),	//
	//
	texture2DVideo(ptrIteratorImage->getW(), ptrIteratorImage->getH())
    {
    // animation
	{
	this->t = 0;  // protected dans Animable
	}

    //video
	{
	this->tabPixelVideo = ptrIteratorImage->first();
	}
    }

VideoTextureCuarray::~VideoTextureCuarray()
    {
    //rien
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
void VideoTextureCuarray::process(uchar* tabPixelsGM , uint w , uint h , const DomaineMath& domaineMath)
    {
    // 1) copier tabPixelVideo dans texture2DVideo
    // 2) appeler le kernel de contour

    // TODO
    }

/**
 * Override
 * Call periodicly by the API
 */
void VideoTextureCuarray::animationStep()
    {
    t++;

    this->tabPixelVideo = ptrIteratorImage->next();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

