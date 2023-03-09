#include "SliceGM.h"

#include <iostream>
#include <assert.h>

#include "GM.h"
#include "Maths.h"
#include "Hardware.h"
#include "Kernel.h"

using std::cout;
using std::endl;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void reductionIntraThreadGM(float* tabGM,int nbSlice);
extern __global__ void ecrasementGM(float* tabGM, int moitier);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

SliceGM::SliceGM(Grid grid , int nbSlice , double* ptrPiHat , bool isVerbose) :
	RunnableGPU(grid, "SliceGM-" + to_string(nbSlice), isVerbose), // classe parente
//
	nbSlice(nbSlice), //
	ptrPiHat(ptrPiHat) //
    {
    // ntabGM
	{
	this->nTabGM = -1; // TODO SliceGM

	}

    // MM
	{
	this->sizeTabGM = -1; //  TODO SliceGM // [octet]

	}
    }

SliceGM::~SliceGM(void)
    {
    //MM (device free)
	{
	//TODO SliceGM
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * <pre>
 * Idea globale
 *
 *	Etape 0 : Promotion d'un tableau en GM (MemoryManagement MM)
 * 	Etape 1 : Reduction intra-thread dans un tableau promu en GM
 * 	Etape 2 : Reduction du tableau en GM par ecrasement hierarchique 2 à 2
 * 		  On lance les kernels d'ecrasement depuis le host (chef d'orchestre)
 * 	Etape 4 : Copy du resultat coter host
 * 	Etape 5 : Destruction GM
 * </pre>
 */
void SliceGM::run()
    {
    //TODO SliceGM // call the kernel (asynchrone)

    reductionGM();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Etape 1 : Lancement des kernels d'ecrasement depuis le host, dans une boucle,
 * Etape 2 : recuperer le resultat coter host
 * Etape 3 : finaliser le calcule de PI
 */
void SliceGM::reductionGM()
    {
    int midle = nTabGM >> 1; // nTabGM/2;

    // TODO SliceGM

    // Warning:		Utiliser une autre grille que celle heriter de la classe parente dg, db
    // 			Votre grid ici doit avoir une taille speciale!
    // 			N'utiliser donc pas les vraibales dg et db de la super classe

    // Tip:		Il y a une methode dedier pour ramener un float cote host
    //
    //				float resultat;
    //				GM::memcpyDtoH_float(&resultat,ptrResultGM);
    }

// BruteForce:
//
//	Observation:
//
//		(O1) 	Il faut bruteforcer uniquement le dg dg du kernel de reduction intraThread.
//			La grid pour les ecrasement est elle imposer par la taille du tableau en GM a reduire.
//
//		(O2)
//			La taille du tableau promu en GM doit etre une puissance de 2, pour pouvoir lancer les ecrasements
//			Or tabGM a autant de cases qu il y a de threads totals
//			Et on aimerait bien respecter les deux heuristiques
//
//				(H2)	nbBlock % nbMp = 0
//				(H1) 	nbThreadByBlock % nbCoreByMp = 0
//
//	Question :
//
//			Peut on respecter la conrainte "puissance de 2" et les heuristics?
//
//	TIP:
//			Dans le bruteforce on peut specifier deux iterateurs, qui se baladent sur dg et db
//			Il faut que cette grille respecte la contraite (prioriter) et si on pas de chance, pas les heuristiques
//
//			Regarder l'implementation speciale de SliceGM dans mainBrutefore.cpp.
//			On fait une propre grille dedier aux proprietes de l' exercice
//

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
