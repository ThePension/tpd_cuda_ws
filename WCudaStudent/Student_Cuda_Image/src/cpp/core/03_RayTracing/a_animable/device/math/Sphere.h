#pragma once

#include "Maths.h"
#include "both_define.h"

class Sphere
    {
    public:

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	__host__ Sphere(float3 centre , float rayon , float hueStart) :
		centre(centre), //
		rayon(rayon), //
		hueStart(hueStart)
	    {
	    // Tools
	    this->rCarre = rayon * rayon;
	    this->T = asinf(2 * hueStart - 1) - 3 * PI_FLOAT / 2;
	    }

	/**
	 * required by example for  new Sphere[n]
	 */
	__BOTH__
	Sphere()
	    {
	    // rien
	    }

	// constructeur copie automatique car pas pointeur dans Sphere

	// Interdit with cm
//	 virtual ~Sphere()
//	    {
//	    // rien
//	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	float h2(float2 xySol)
	    {
	    float a = (centre.x - xySol.x);
	    float b = (centre.y - xySol.y);
	    return a * a + b * b;
	    }

	__device__
	bool isEnDessous(float h2)
	    {
	    return h2 < rCarre;
	    }

	__device__
	float dz(float h2)
	    {
	    return sqrtf(rCarre - h2);
	    }

	__device__
	float brightness(float dz)
	    {
	    return dz / rayon;
	    }

	__device__
	float distance(float dz)
	    {
	    return centre.z - dz;
	    }

//	__device__
//	float getHueStart()
//	    {
//	    return hueStart;
//	    }

	__device__
	float hue(float t)
	    {
	    return 0.5f + 0.5f * sinf(t + T + 3 * PI_FLOAT / 2);
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    public:

	// Inputs
	float rayon;
	float3 centre;
	float hueStart;

	// Tools
	float rCarre;
	float T;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

