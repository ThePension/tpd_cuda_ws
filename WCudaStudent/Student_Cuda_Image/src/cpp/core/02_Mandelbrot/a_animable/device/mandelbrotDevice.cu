#include "Thread2D.cu.h"
#include "cudas.h"

#include "real.h"
#include "MandelbrotMath.cu.h"

#include "DomaineMath.h"
#include "Indices.cu.h"


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

__global__ void mandelbrot(uchar4* tabPixelsGM , uint w , uint h , DomaineMath domaineMath , int n)
    {
    MandelbrotMath mandelbrotMath(n);

    // TODO Mandelbrot GPU :
    //
    // entrelacement
    // s -> (i,j) -> (x,y)
    // appeler colorXY

    double x;
    double y;
    //domaineMath.toXY(i, j, &x, &y); // x et y doivent etre en double! Caster ensuite en real lors du passage à colorXY

    // Probleme : Choix a faire pour le type de (x,y) :
    //
    //			- Travailler en float pour plus de performance?
    //			- Travailler en double pour pouvoir zoomer plus loin dans le fractale?
    //
    // Solution : Travailler avec le typedef real definit dans "real.h"
    //		  Specifier dans "real.h" si vous souhaitez travailler en float ou en double
    //	          Ainsi on passe facilement et proprement d'une version float a une version double
    //
    // Note : domaineMath.toXY travaille lui toujours en double pour vous permettre les deux possibilites ci-dessus
    //
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

