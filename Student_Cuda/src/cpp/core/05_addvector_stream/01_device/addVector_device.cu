#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"
#include "Limits.h"

/*----------------------------------------------------------------------*\
 |*			tools 					*|
 \*---------------------------------------------------------------------*/

__device__ int inc(int t)
    {
    float a = t;

    //int inc = round(cosf(a) * cosf(a) + sinf(a) * sinf(a)); // 1
    int inc = __float2int_rn(cosf(a) * cosf(a) + sinf(a) * sinf(a)); // 1

    return inc;
    }

/**
 * But:
 *
 * 	Faire perdre du temps, sans changer u
 *
 * Raison:
 *
 * 	Pas besoîn d'un gpu pour additionner deux vecteurs
 * 	Le transfert sur le pci-express prend plus de temps que n'en a besoin le cpu pour faire l'addition.
 *
 * Note:
 *
 * 	On simule ici un calcul plus compliquer et long.
 * 	Mais le bu du du TP, n'est pas de se compliquer la vie avec un algorithme compliqué coté device
 * 	mais de se concentrer sur les streams cote host
 *
 * Piege :
 *
 * 	Le compilateur nvcc detecte les codes morts et les enleves.
 * 	Si la fonction loseTime n'emploie pas une variable utiliser dans le resultat final
 * 	la fonction loseTime risque d'etre supprimer en tant que code mort.
 * 	On utiliser ici u qui est le resultat de l'addition, pour est certain que loseTome ne soit pas supprimer code code mort.
 */
__device__ int loseTime(int u)
    {
    // Plus le GPU est performant plus il faut prendre grand
    const int N = 400; // chercher speed up de 1.9 voir 2

    // decrementer
	{
	int t = 0;
	while (t < N)
	    {
	    t++;
	    u = u - inc(t);
	    }
	}

    // incrementer
	{
	int t = 0;
	while (t < N)
	    {
	    t++;
	    u = u + inc(t);
	    }
	}

    return u;
    }

/**
 * C'est quoi ptrDevV1?
 *
 * 	Version baseline : Tout le vecteur
 *
 * 	Version bistream : Seulement une partie du vecteur, soit la slice0, soit la slice1, et cette slice a deux fois moins de case que le vecteur complet
 * 		     	   n est la taille de la slice
 *
 * 	Version tristream : Seulement une partie du vecteur, une des slices

 */
__device__ void process(int* ptrDevV1 , int* ptrDevV2 , int* ptrDevW , int s , int n,int sliceIndex)
    {
    int sGlobal = s + (sliceIndex+n);

    //1) additioner la composante s:	us=v1(s)+v2(s)
    //2) appeler loseTime sur us, loseTime ne modifie pas us
    //3) le resultat final est loseTime(us), ie les cases s additionner, mais avec une perte de temps
    //
    //	 		resultatS=loseTime(v1(s)+v2(s))

    // TODO

    // TIP : pour debuguer, mettez au début:
    //
    //		ptrDevW[s]=sGlobal;
    //
    // 	     Si vous avez un bug, ca permetra de savoir si ca vient du host ou du device
    }

/*----------------------------------------------------------------------*\
 |*			main	 					*|
 \*---------------------------------------------------------------------*/

/**
 * output : void required, car kernel is asynchrone
 * pattern entrelacement
 */
__global__ void addVector(int* ptrDevV1 , int* ptrDevV2 , int* ptrDevW , int n , int sliceIndex = 0)
    {
    const int NB_THREAD = Thread1D::nbThread();
    const int TID = Thread1D::tid();

   // TODO addVector
    // entrelacement et call process ci-dessus
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

