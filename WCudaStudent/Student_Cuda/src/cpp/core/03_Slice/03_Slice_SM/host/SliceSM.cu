#include "SliceSM.h"

#include <iostream>
#include <assert.h>

#include "GM.h"
#include "SM.h"

using std::cout;
using std::endl;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void sliceSM(int nbSlice,float* ptrPiHatGM);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

SliceSM::SliceSM(const Grid& grid , int nbSlice , double* ptrPiHat , bool isVerbose) :
	RunnableGPU(grid, "SliceSM-" + to_string(nbSlice), isVerbose), // classe parente
	//
	ptrPiHat(ptrPiHat), //
	nbSlice(nbSlice) //
    {
    this->ptrPiHatGM = NULL;
    this->sizeSM = -1; //TODO SliceSM

    // MM
	{
	// TODO SliceSM (pas oublier de mettre a zero, avec mallocfloat0 par exemple)

	// Tip:		Il y a une methode dedier pour malloquer un float cote device et l'initialiser a zero
	//
	//		   GM::mallocfloat0(&ptrGM);
	}
    }

SliceSM::~SliceSM(void)
    {
    // TODO SliceSM
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void SliceSM::run()
    {
    // Etape 1 : lancer le kernel
    // Etape 2 : recuperer le resultat coter host (par exemple avec memcpyDToH_float)
    // Etape 3 : finaliser le calcul de PI

    // TODO SliceSM
    }

// BruteForce:
//
//	Observation:

//		(O2)
//			La taille des tableau promu en SM doit etre une puissance de 2, pour pouvoir lancer les ecrasements
//			Or tabSM a autant de cases qu il y a de threads èar blocks
//			Et on aimerait bien respecter l'heuristique
//
//				(H2) 	nbThreadByBlock % nbCoreByMp = 0
//
//	Question :
//
//			Peut on respecter la contrainte "puissance de 2" et l'heuristique (H2)?
//
//	Reponse:
//			Tout depend du nombre de core par MP, mais c'est souvent 32 ou 64 ou 128
//			ie dans les 3 cas une puissance de 2, youpie
//
//			Comme il y a max 1024 threads par block, il n'y a pas beaucoup de possibilites
//
//				1024 512 256 128 64 32
//
//			Lors du forcebrute, il faut donc adapter les grilles a cette contrainte.
//			Regarde a cet effet la methode sliceSM dans mainBruteforce.cpp
//			et plus particulierement la methode bruteforceReduction utilisee.
//

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
