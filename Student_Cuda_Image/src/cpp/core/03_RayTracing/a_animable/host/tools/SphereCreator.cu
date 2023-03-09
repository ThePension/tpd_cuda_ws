#include "SphereCreator.h"

#include <iostream>
#include <assert.h>

#include "Aleas.h"
#include "Maths.h"
#include "HM.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

static bool IS_MEMORY_DMA = true;

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

/**
 * nbSpheres>=4
 */
SphereCreator::SphereCreator(int nbSpheres , int w , int h , int bord) : //
	nbSpheres(nbSpheres), //
	w(w), //
	h(h), //
	bord(bord)

    {
    assert(nbSpheres >= 4);

    if (!IS_MEMORY_DMA)
	{
	this->tabSphere = new Sphere[nbSpheres]; // required default constructeur of type : sphere(void)
	}
    else
	{
	HM::malloc(&tabSphere, nbSpheres * sizeof(Sphere));
	}

    createSphereAll();
    }

SphereCreator::~SphereCreator()
    {
    if (!IS_MEMORY_DMA)
	{
	delete[] tabSphere;
	}
    else
	{
	HM::free(tabSphere);
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

Sphere* SphereCreator::getTabSphere()
    {
    return tabSphere;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void SphereCreator::createSphereAll(void)
    {
    createSphereBack();
    createSphereFront();
    createSphereAleatoire();
    }

/**
 * La premiere, centrée, très grande, au fond
 */
void SphereCreator::createSphereBack(void)
    {
    float3 centre;

    centre.x = h / 2;
    centre.y = w / 2;
    centre.z = ZMAX * 2; // plus grand que ZMAX

    float rayon = std::min(w / 2, h / 2);
    float hue01 = 1;

    tabSphere[0] = Sphere(centre, rayon, hue01);
    }

/**
 * Les dernieres, centrées, très petite, très proche
 */
void SphereCreator::createSphereFront(void)
    {
    float hue01 = 1;
    float rayon = std::min(w / 10, h / 10); // disons
    float z = ZMIN - (rayon + rayonMax());

    float dhue = 0.2;
    float dz = 40;
    float drayon = dz / 2;

    for (int i = nbSpheres - 3; i < nbSpheres; i++)
	{
	float3 centre;

	z -= dz;
	rayon -= drayon;
	hue01 -= dhue;

	centre.x = h / 2;
	centre.y = w / 2;
	centre.z = z;

	tabSphere[i] = Sphere(centre, rayon, hue01); // Warning : sphere stack copier dans sphere heap, ok car pas ptr dans Sphere
	}
    }

/**
 * Toute sauf la premiere
 */
void SphereCreator::createSphereAleatoire(void)
    {
    Aleas aleas;

    for (int i = 1; i < nbSpheres - 3; i++)
	{
	float3 centre;

	centre.x = aleas.uniformeAB(0 + bord, h - bord);
	centre.y = aleas.uniformeAB(0 + bord, w - bord);
	centre.z = aleas.uniformeAB(ZMIN, ZMAX);

	float rayon = aleas.uniformeAB(20, rayonMax());
	float hue01 = aleas.uniforme01();

	tabSphere[i] = Sphere(centre, rayon, hue01); // Warning : sphere stack copier dans sphere heap, ok car pas ptr dans Sphere
	}
    }

int SphereCreator::rayonMax()
    {
    return w / 10;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

