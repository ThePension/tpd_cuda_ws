#include <assert.h>

#include "Thread2D.cu.h"
#include "cudas.h"
#include "Indices.cu.h"

#include "Sphere.h"
#include "nbSphere.h"

#include "raytracingCM.cu.h"
#include "RaytracingMath.cu.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __device__ void work(uchar4* tabPixelsGM, uint w, uint h, float t, Sphere* tabSpheresDev, int nbSpheres);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

__global__ void kernelRaytacingGM(uchar4* tabPixelsGM , uint w , uint h , float t , Sphere* tabSpheresGM , int nbSpheres)
    {
    // TODO Raytracing GPU GM

    // Indications :
    //		(I1) Call methode work with good input
    // 		(I2) work contain the algo
    //		(I3) The algo is the same with the GM,CM,SM of TP Ractracing
    }

__global__ void kernelRaytacingSM(uchar4* tabPixelsGM , uint w , uint h , float t , Sphere* tabSpheresGM , int nbSpheres)
    {
    // TODO Raytracing GPU SM

    // Indications :
    //		(I1) Copier les sphere de GM to SM
    // 		(I2) Call work with good input
    //		(I3) Implementer une methode copyGMtoSM
    }

__global__ void kernelRaytacingCM(uchar4* tabPixelsGM , uint w , uint h , float t , int nbSpheres)
    {
    // TODO Raytracing GPU CM

    // Indications :
    //		(I1) call work with good input
    // 		(I2) TAB_SPHERES_CM est une variable globale a ce fichier! (Voir le debut de ce fichier, include rayTracingCM.h)
    }

__global__ void kernelRaytacingCM2SM(uchar4* tabPixelsGM , uint w , uint h , float t , int nbSpheres)
    {
    // TODO Raytracing GPU SM_BY_CM

    // Indications :
    //		(I1) Copier les sphere de CM to SM
    // 		(I2) Call work with good input
    //		(I3) Implementer une methode copyCMtoSM
    //		     ou : Tip : renommer copyGMtoSM en copyDevToSM et utiliser copyDevToSM avec les bons inputs
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * Methode commune au 3 kernel ci-dessus.
 * Ici on ne sait pas si derriere tabSpheresDev, c'est
 * 	- de la GM?
 * 	- de la SM?
 * 	- de la CM?
 * Pas d'importance, c'est un pointeur et on travail avec!
 */
__device__ void work(uchar4* tabPixelsGM , uint w , uint h , float t , Sphere* tabSpheresDev , int nbSpheres)
    {
    // TODO Raytracing work device side

    // create RaytracingMath
    // entrelacement
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

