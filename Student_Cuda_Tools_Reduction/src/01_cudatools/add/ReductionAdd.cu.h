#pragma once

#include "Thread2D.cu.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

class ReductionAdd
    {
    public:

	/**
	 * Hypothese:
	 *
	 * 	(H1) 	On suppose que T est un type simple sur lequel atomicAdd existe
	 *
	 * Exemple :
	 * 		ReductionAdd::reduce(tabSm,ptrDevResultatGM);
	 *
	 * Contraintes :
	 *
	 * 	(C1) 	|tabSM| puissance de 2, comme 2,4,8,16,32,64,128,256,512,1024
	 * 	(C2)	|ThreadByBlock|=|tabSM|
	 * 	(C3)	Reduction intra-thread laisser a l'utilsiateur (ie remplissage de tabSM)
	 *
	 * Warning :
	 *
	 * 	(W1)	ptrResultGM n'est pas un tableau, mais un scalaire contenant le resultat final
	 * 	(W2)	Oubliez pas le MM pour  ptrResultGM
	 * 	(W3)	Oubliez pas l'initialisation de ptrResultGM
	 * 		Exemples :
	 *
	 * 			addition 	: initialisation a zero avec un
	 *
	 * 						GM::memclear(...)
	 *
	 * 			multiplication  : initialisation a 1 avec un
	 *
	 * 						GM::memcpyHtoD(...)
	 *
	 * 			ou d'eun seul coup au malloc
	 *
	 * 				GM::mallocfloat0(&ptrResultGM);
	 * 				GM::mallocInt0(&ptrResultGM);
	 *
	 */
	template <typename T>
	static __device__ void reduce(T* tabSM, T* ptrResultGM)
	    {
	    // Rappel :
	    // 		|ThreadByBlock|=|tabSM| .
	    // 		Il y autant de case en SM que de thread par block.
	    //		Chaque thread possede son armoire en SM
	    //		1 thread <---> 1 armoire

	    // TODO ReductionAdd
	    // reductionIntraBlock
	    // reductionInterblock

	    // __syncthreads();// pour touts les threads d'un meme block, necessaires? ou?
	    }

    private:

	/*--------------------------------------*\
	|*	reductionIntraBlock		*|
	 \*-------------------------------------*/

	/**
	 * used dans une boucle in reductionIntraBlock
	 */
	template <typename T>
	static __device__ void ecrasement(T* tabSM, int middle)
	    {
	    // Indications :
	    //	(I1) je suis un thread, je dois faire quoi ?
	    // 	(I2) Tous les threads doivent-ils faire quelquechose?
	    //  (I3) Travailler sous l hypothese d'une grid2d,avec Thread2D

	    // TODO ReductionAdd

	    // __syncthreads();// pour touts les threads d'un meme block, necessaires? ou?

	    }

	/**
	 * Sur place, le resultat est dans tabSM[0]
	 */
	template <typename T>
	static __device__ void reductionIntraBlock(T* tabSM)
	    {
	    // Ecrasement sucessifs dans une boucle (utiliser la methode ecrasement ci-dessus)

	    // TODO ReductionAdd

	    // __syncthreads();// pour touts les threads d'un meme block, necessaires? ou?
	    }

	/*--------------------------------------*\
	|*	reductionInterblock		*|
	 \*-------------------------------------*/

	template <typename T>
	static __device__ void reductionInterBlock(T* tabSM, T* ptrResultGM)
	    {
	    // Indication:
	    //		(I1) Utiliser atomicAdd(pointeurDestination, valeurSource);
	    //		(i2) Travailler sous l hypothese d'une grid2d,avec Thread2D

	    // TODO ReductionAdd

	    // __syncthreads();// pour touts les threads d'un meme block, necessaires? ou?
	    }

    };

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
