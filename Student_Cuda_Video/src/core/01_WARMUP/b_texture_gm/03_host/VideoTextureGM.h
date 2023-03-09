#pragma once

#include <iostream>
#include "cudas.h"

#include "IteratorImageGray_I.h"
#include "Animable_I.h"
#include "Texture2D_GM.h"

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class VideoTextureGM: public Animable_I<uchar>
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	VideoTextureGM(const Grid& gridMinMax , IteratorImageGray_I* ptrIteratorImage);
	virtual ~VideoTextureGM(void);

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

	static Grid bestGridConstrastor();

    private:

	void minMax(uchar* tabPixelsGM , string title = "");
	void constrator(uchar* tabPixelsGM);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	Grid gridMinMax;
	Grid gridConstrastor;

	// Tools
	int wh;
	IteratorImageGray_I* ptrIteratorImage;
	uchar* tabPixelVideo;
	size_t sizeImage;

	// Tools MinMax
	int* tabMinMax; 	// host side   (contient min et max)
	int* tabMinMaxGM;	// device side (contient min et max)

	int* ptrMinGM; // pointe sur la premiere case de tabMinMax
	int* ptrMaxGM; // pointe sur la deuxieme case de tabMinMax

	size_t sizeMinMax;
	size_t sizeSM;

	// Tools Texture
	Texture2D_GM<uchar> texture2D_GM;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
