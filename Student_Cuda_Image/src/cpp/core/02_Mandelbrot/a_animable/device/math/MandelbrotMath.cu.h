#pragma once

#include <math.h>
#include <cuda_fp16.h>

#include "real.h"
#include "Maths.h"


#include "Colors.cu.h"

#include "DomaineMath.h"


/*--------------------------------------*\
 |*		Helper type		*|
 \*-------------------------------------*/

#ifdef MANDELBROT_HALF
#define DEUX (half)2
#define QUATRE (half)4
#define ZERO (half)0
#endif

#ifdef MANDELBROT_FLOAT
#define DEUX 2.f
#define QUATRE 4.f
#define ZERO 0.f
#endif

#ifdef MANDELBROT_DOUBLE
#define DEUX 2.0
#define QUATRE 4.0
#define ZERO 0.0
#endif

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	__device__ MandelbrotMath(int n) :
		n(n)
	    {
	    //
	    }

	__device__
	   virtual ~MandelbrotMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorXY(uchar4* ptrColorIJ , real x , real y)
	    {
	    // TODO Mandelbrot GPU

	    // Calculer la suite en (x,y) et recuperer l'indice d'arret de la suite
	    // Colorier : 	Il faut convertir l'indice d'arret en une hue01!
	    //			Calcul dans quel type? float

	    // Conseil:
	    // 		Etape 1 : 	Commencer par afficher une image uniforme grise (128 par exemple)
	    // 				pour valider tout le pipeline en amont
	    //
	    // 		Etape 2:	Puis une fois que l'image grise est valider, attaquer montecarlo

	    // debug temp
	    //		{
	    //		ptrColorIJ->x = 128;
	    //		ptrColorIJ->y = 128;
	    //		ptrColorIJ->z = 128;
	    //		ptrColorIJ->w = 255; // opacity facultatif
	    //		}
	    }

    private:

	/**
	 * Warning: define real in real.h (real=float or real=double or real= half)
	 */
	__inline__
	__device__
	int suite(real x , real y)
	    {
	    // TODO Mandelbrot GPU

	    // Utiliser dans vos formules les variable :
	    //
	    //		DEUX
	    //		QUATTRE
	    //		ZERO
	    //
	    // definit au debut de ce fichier. Est-utile pour  passer facilement d'une version fp64 (double) fp32(float) fp16(half)

	    // Calculer la suite en (x,y) jusqu'à n, à moins que critere arret soit atteint avant
	    // return le nombre d'element de la suite calculer, ie un entier
	    }

	//
	// Risque:
	//
	// 	Un des risque est de faire une boucle infinie
	//
	// Analyse:
	//
	// 	Comme il n'y pas de ecran physiquement brancher sur le serveur, les kernels n'ont pas de timeout
	// 	Le kernel n'est donc pas stopper apres les 2 secondes de timeout par defaut
	// 	Vous avez donc un risque de laisser le serveur inutilisable pour les autres utilisateus de la machine
	//
	// Consequence:
	//
	// 	Checker bien votre code avant de le lancer
	//
	// 	Arreter bien votre processus:
	//		- carrer rouge eclipse
	//		- linux_kill_cuda (dans la trousse a outil d'exlipse)
	//		- a la racine du projet : cbicc cuda kill
	//
	// 	Verifier avec :
	//		htop 				que votre processus est bien detruit  (filter .run)
	//		nvidia-smi --loop=1		que vous n'employez plus le gpu
	//
	// 	Sinon il y a de grandes chances qu'il faille redemarer le server et les autres utilisateurs de la machine ne vont pas etre content.
	//
	// Info:
	//
	//	On peut tester l etat du serveur (pipeline de rendu openGL) via
	//
	//		gl glxgears
	//
	//	Si la fenetre mais du temps a s'ouvrir . c'est pas bon signe
	//	Si elle ne s'ouvre pas, je dois redemarer le server

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	int n;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
