#pragma once

#include <iostream>
#include "cudas.h"

#include "IteratorImageGray_I.h"

#include "Surface2D.h"

#include "Animable_I.h"


using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class VideoSurface: public Animable_I<uchar>
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	VideoSurface(const Grid& gridDilatation , IteratorImageGray_I* ptrIteratorImage, uchar seuil0255);
	virtual ~VideoSurface(void);

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

    public:

	static Grid bestGridSeuillage();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inpus
	Grid gridSeuillageBest;
	uchar seuil0255;

	// Tools
	int wh;
	IteratorImageGray_I* ptrIteratorImage;
	uchar* tabPixelVideo;

	size_t sizeImage;

	// Tools Surface/cuarray
	Surface2D<uchar> surface2d;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
