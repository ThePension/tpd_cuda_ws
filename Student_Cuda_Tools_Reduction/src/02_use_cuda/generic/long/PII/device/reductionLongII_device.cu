#include "Thread1D_long.cu.h"
#include "cudas.h"

#include "Reduction.cu.h"
#include "Lock.cu.h"

#include <stdio.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __device__ void reductionIntraThread(long* tabSM);

// Operateur reduction
static __device__ long add(long x , long y);
static __device__ void addAtomic(long* ptrX , long y);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * TID partout en tabSM
 */
__global__ void KLongProtocoleII(long* ptrSumGM)
    {
    // TODO ReductionLongII
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * TID partout en tabSM
 */
__device__ void reductionIntraThread(long* tabSM)
    {
    // Rappel : Dans le protocoleII on cherche a calculer
    //
    //			x=x+i avec i in [0,N]
    //
    //		ie la somme des entiers allant de 1 à N
    //
    //		Ces entiers sont mis dans tabSM, puis on somme le contenu des tabSM
    //
    // Technique : Chaque thread depose en tabSM, sont TID!
    //
    // Rappel	 : Chaque thread possede une et exactement une case en tabSM (relation 1-1)
    //
    // Warning   : L'utilisation du type long permet dans le protocoleII de sommer plus d'entier.
    //
    //		   Pour sommer plus d'entier, on prend plus de thread (cf relation 1-1) ci-dessus.
    //
    //             Plus de thread, c'est une grille plus grande, et dès lors le TID va devenir tres grand, plus grand que MAX_INT
    //
    //		Faux:		const int TID=Indice1D.tid(); // ne va pas fonctionner pour pour les grandes grids car max(TID)>MAX_INT
    //
    //		Juste (v1):	const long TID=((long)blockDim.x * (long) blockIdx.x)+ (long)threadIdx.x;
    //
    //		Juste (V2):	const long TID=Thread1D_long::tid();
    //
    //		Juste (V3):	const long TID=Thread2D_long::tid();
    //
    // Attention
    //
    //		Tout ceci est vrai seulement ici, dans le cadre du protocoleII

    // TODO ReductionLongII

    // pour TID       utiliser const long TID=Thread2D_long::tid();		// (nouvelle methode)
    // pour TID_LOCAL utiliser const int TID_LOCAL=Thread2D::tidLocal();	// (methode habituelle)
    }


/*----------------------------*\
|*	Operateur reduction    *|
 \*---------------------------*/

__device__ long add(long x , long y)
    {
    // TODO ReductionLongII
    }

/**
 * Utiliser la methode system, si elle existe
 *
 * 	atomicAdd(pointeurDestination, valeurSource)
 *
 * ou la technique du lock vu precedement!
 *
 * Question : atomicAdd pour les long existe?
 */
__device__ int volatile mutex = 0;	//variable global
__device__ void addAtomic(long* ptrX , long y)
    {
    Lock locker(&mutex);
    locker.lock();

    // TODO ReductionLongII

    locker.unlock();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

