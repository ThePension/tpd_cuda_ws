#include "Thread2D.cu.h"
#include "Thread1D.cu.h"
#include "cudas.h"
#include "Maths.h"

#include "Calibreur.cu.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

__global__ void kConstrastor(uchar* tabPixelsGM , uint wh , int* ptrMinGM , int* ptrMaxGM)
    {
    // Goal  : [min,max]-> [0,255]
    //
    // Tools : Calibreur<float> calibreur(Interval<float> depart, Interval<float> arriver)
    //	       calibreur.calibrer(&toCalibrer);
    //	       travailler en float pour la calibration
    //
    // Astuce:  Interval<float> intervalArriver(0, 255.9f); // 255.9f sinon on obtient jamais 255, mais 254 comme max

    float min = *ptrMinGM;
    float max = *ptrMaxGM;

    // TODO kConstrastor
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

