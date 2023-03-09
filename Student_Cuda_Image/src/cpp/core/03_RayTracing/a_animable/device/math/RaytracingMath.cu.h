#pragma once

#include <math.h>
#include "Maths.h"
#include "Limits.h"

#include "Sphere.h"
#define FLOAT_MAX 1e+6

#include "Colors.cu.h"

class RaytracingMath
    {
    public:

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	__device__ RaytracingMath(Sphere* tabSpheresDev , int nbSpheres , float t) : //
		tabSpheresDev(tabSpheresDev), //
		nbSpheres(nbSpheres), //
		t(t)
	    {
	    // rien de plus
	    }

	__device__  virtual ~RaytracingMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorIJ(uchar4* ptrColorIJ , int i , int j)
	    {
	    // Note : On travaille sans domaineMath ici (choix), donc pas x y en double, mais i j en int
	    float2 xySol; // convertion simple en real, car la chaine de calul est ensuite ne real
	    xySol.x = i;
	    xySol.y = j;

	    colorIJ(xySol, ptrColorIJ); // update ptrColorIJ

	    ptrColorIJ->w = 255; // opacity facultatif

	    // Conseil:
	    // 		Etape 1 : 	Commencer par afficher une image uniforme grise (128 par exemple)
	    // 				pour valider tout le pipeline en amont
	    //
	    // 		Etape 2:	Puis une fois que l'image grise est valider, attaquer raytracing

	    //   debug temp
		{
//	    		ptrColorIJ->x = 128;
//	    		ptrColorIJ->y = 128;
//	    		ptrColorIJ->z = 128;
//	    		ptrColorIJ->w = 255; // opacity facultatif
		}
	    }

    private:

	__inline__
	__device__
	void colorIJ(const float2& xySol , uchar4* ptrColorIJ)
	    {
	    // TODO Raytracing GPU math
	    // process the color for the pixel (i,j)
	    // use methode of classe Sphere

	    // Indications:
	    //
	    // 		(I1) 	Voici la sequence des elements a calculer
	    //
	    //				h2 (hCarrer)
	    //  			isEndessous
	    //  			dz
	    //  			distance
	    //  			brightness
	    //
	    //		(I2)	Voir les attributs de classes (en bas de ce fichier)
	    //
	    //		(I3)	Pour chaque pixel:
	    //				(S1) Parcourir toutes les spheres (cf attributs)
	    //				(S2) Pour chacune d'entre elle, regarder si vous etes en dessous
	    //				(S3) Si vous etes en dessous, calculer la distance, et memoriser
	    //				     la sphere qui est la plus proche, de toutes celles deja parcourues
	    //				(S4) Finalement prenez la hue de la sphere la plus proche
	    //				(S5) Adapter la brightness selon la distance qui separe le pixel du centre projet de la sphere,
	    //				     pour un effet 3d plus realiste (truc d'infographiste)
	    //

	    // Debug truc:
	    //
	    //	(D1) Mettez en commentaire le contenu de votre premier if et colorier en rvb en rouge!
	    //	     Vous devrier voir des decoupes de sphere dans les bords de l'image!
	    //

	    // Optimisations : Pistes:
	    //
	    // 	(O1) Essayer de supprimer la thread divergence
	    //	(O2) Optimisation du dg db
	    // 	(O3) Minimiser acces a la GM (sphere i dans un registre : Sphere spherei=...), au lieu d'un pointeur? d'un indice?
	    //	(O4) Stocker les attributs de la sphere la plus proche (hue par exemple)  et pas la sphere elle meme
	    //	(O5) ...
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	Sphere* tabSpheresDev;
	int nbSpheres;
	float t;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
