#include <iostream>
#include <assert.h>

#include "VideoTextureGM.h"
#include "GM.h"
#include "Stream.h"
#include "Hardware.h"
#include "Limits.h"
#include "Texture2D_GM.h"

using std::cout;
using std::cerr;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void kMinMaxInt(uchar* tabPixelsGM , uint wh , int* ptrDevMin, int* ptrDevMax);
extern __global__ void kConstrastorTex(uchar* tabPixelsGM,cudaTextureObject_t tex2dGM , uint w , uint h , int* ptrMinGM , int* ptrMaxGM);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

VideoTextureGM::VideoTextureGM(const Grid& gridMinMax , IteratorImageGray_I* ptrIteratorImage) :
	Animable_I<uchar>(gridMinMax, ptrIteratorImage->getW(), ptrIteratorImage->getH(), "Video_texture_gm_uchar"), //
	//
	ptrIteratorImage(ptrIteratorImage), //
	//
	gridMinMax(gridMinMax), //
	gridConstrastor(bestGridConstrastor()), //
	//
	wh(ptrIteratorImage->getWH()), //
	//
	texture2D_GM(ptrIteratorImage->getW(), ptrIteratorImage->getH()) // NEW
    {
    // Tools
    this->t = 0; // protected dans Animable

    this->sizeImage = sizeof(uchar) * wh;

    //video
	{
	this->tabPixelVideo = ptrIteratorImage->first();
	}

    // Tools : minmax
	{
	// host
	this->tabMinMax = new int[2];

	// device
	this->sizeMinMax = 2 * sizeof(int); // 2 car min et max
	this->sizeSM = gridMinMax.threadByBlock() * sizeMinMax;

	GM::malloc(&tabMinMaxGM, sizeMinMax);

	this->ptrMinGM = tabMinMaxGM;
	this->ptrMaxGM = tabMinMaxGM + 1;
	}
    }

VideoTextureGM::~VideoTextureGM()
    {
    // MM
	{
	GM::free(tabMinMaxGM);
	}

    delete[] tabMinMax;
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
void VideoTextureGM::process(uchar* tabPixelsGM , uint w , uint h , const DomaineMath& domaineMath)
    {
    // 1) Copier tabPixelVideo dans tabPixelsGM
    // 2) Associer tabPixelsGM a la texture :  texture2D_GM.see(tabPixelsGM);  // NEW
    // 3) Calculer le min et max de tabPixelsGM
    // 4) Contraster tabPixelsGM
    // 5) Verifier que le contrastage a fonctionner, ie que (min,max)=(0,255)

    // TODO

    minMax(tabPixelsGM, "Before");
    constrator(tabPixelsGM);
    }

/**
 * Override
 * Call periodicly by the API
 */
void VideoTextureGM::animationStep()
    {
    t++;

    this->tabPixelVideo = ptrIteratorImage->next();
    }

/*-------------------------*\
 |*	private		    *|
 \*-------------------------*/

void VideoTextureGM::constrator(uchar* tabPixelsGM)
    {
    int min = tabMinMax[0];
    int max = tabMinMax[1];

    if (min != max || (min != 0 && max != 255))
	{
	// TODO
	assert(false);

	// Check (benchmark && bruteforce && rendu final : laisser activer)
	    {
	    minMax(tabPixelsGM, "After ");

	    assert(tabMinMax[0] == 0);
	    assert(tabMinMax[1] == 255);
	    }
	}
    }

void VideoTextureGM::minMax(uchar* tabPixelsGM , string title)
    {
    // Warning : reinitialiser a chaque fois!
	{
	tabMinMax[0] = Limits::MAX_INT; 	// init min
	tabMinMax[1] = 0;			// init max

	GM::memcpyHToD(tabMinMaxGM, tabMinMax, sizeMinMax); // on copie le min et max d'un coup!
	}

    // 1) calculer min/max sur le device dans tabMinMaxGM
    // 2) ramener  min/max sur le host   dans tabMinMax

    // TODO
    assert(false);

    // debug
    //	{
    //	cout << title << " : (min,max)=(" << tabMinMax[0] << "," << tabMinMax[1] << ")" << endl;
    //	}
    }

/*-------------------------*\
 |*	static		    *|
 \*-------------------------*/

Grid VideoTextureGM::bestGridConstrastor()
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

