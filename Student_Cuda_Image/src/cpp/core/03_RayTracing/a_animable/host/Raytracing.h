#pragma once

#include "cudas.h"
#include "Animable_I.h"

#include "Sphere.h"
#include "memoryType.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class Raytracing : public Animable_I<uchar4>
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Raytracing(const Grid& grid,uint w, uint h, float dt,bool isVerbose,int nbSpheres,const MemoryType& memoryType);
	virtual ~Raytracing(void);

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
	virtual void process(uchar4* tabPixelsGM, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

	/**
	 * Override
	 */
	double getInputGO();


    private:

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

	void uploadToDevice(Sphere* tabSpheres);

    private:

	// Inputs
	int nbSpheres;
	float dt; // animation

	// Tools
	size_t sizeSpheres;
	Sphere* tabSpheresGM;
	MemoryType memoryType;
    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
