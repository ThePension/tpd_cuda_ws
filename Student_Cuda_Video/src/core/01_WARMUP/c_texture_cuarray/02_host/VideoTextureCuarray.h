#pragma once

#include <iostream>
#include "cudas.h"

#include "IteratorImageGray_I.h"
#include "Texture2D.h"
#include "Animable_I.h"


using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class VideoTextureCuarray: public Animable_I<uchar>
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	VideoTextureCuarray(const Grid& grid , IteratorImageGray_I* ptrIteratorImage);
	virtual ~VideoTextureCuarray();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void process(uchar* tabPixelsGM , uint w , uint h , const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	IteratorImageGray_I* ptrIteratorImage;
	uchar* tabPixelVideo;

	// Tools : texture
	Texture2D<uchar> texture2DVideo;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
