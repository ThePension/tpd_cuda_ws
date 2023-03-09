#include <assert.h>

#include "cudas.h"

#include "Sphere.h"
#include "nbSphere.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

__constant__ Sphere TAB_SPHERES_CM[NB_SPHERE]; // NB_SPHERE define in nbSphere.h

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ void uploadToCM(Sphere* tabSpheres , int nbSpheres);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __host__ void uploadToCM_v1(Sphere* tabSpheres , size_t sizeSpheres);
static __host__ void uploadToCM_v2(Sphere* tabSpheres , size_t sizeSpheres);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * must be called by host
 * tabSpheres est un tableau de sphere cote host
 */
__host__ void uploadToCM(Sphere* tabSpheres , int nbSpheres)
    {
    assert(nbSpheres == NB_SPHERE);

    size_t sizeSpheres = -1; // TODO taille en octets de toute les spheres

    const bool IS_V1 = true; // TODO essayer avec true et false. Difference de performance?
    if (IS_V1)
	{
	uploadToCM_v1(tabSpheres, sizeSpheres);
	}
    else
	{
	uploadToCM_v2(tabSpheres, sizeSpheres);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__host__ void uploadToCM_v1(Sphere* tabSpheres , size_t sizeSpheres)
    {
    // TAB_SPHERES_CM, va global definit au debut du fichier
    HANDLE_ERROR(cudaMemcpyToSymbol(TAB_SPHERES_CM, tabSpheres, sizeSpheres, 0, cudaMemcpyHostToDevice));
    }

__host__ void uploadToCM_v2(Sphere* tabSpheres , size_t sizeSpheres)
    {
    Sphere* ptrSymbolCM;

    // TAB_SPHERES_CM, va global definit au debut du fichier
    HANDLE_ERROR(cudaGetSymbolAddress((void** )&ptrSymbolCM, TAB_SPHERES_CM)); // on recuper le symbole du ptr de la cm sur le device

    HANDLE_ERROR(cudaMemcpy(ptrSymbolCM, tabSpheres, sizeSpheres, cudaMemcpyHostToDevice)); // on travaille comme si la cm etait un pointeur normal
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

