#include <iostream>
#include <assert.h>
#include <math.h>
#include "Limits.h"

#include "MontecarloUseTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * static
 */
const float MontecarloUseTools::H = 4;

void MontecarloUseTools::performance(double timeS , entier nbDar , bool isOk)
    {
    long nbDarBySeconde = ceil(nbDar / timeS);

    double poidsFlechetteO = (long)nbDar * (long)sizeof(float) * 2;
    double poidsFlechetteGO = poidsFlechetteO / (1024 * 1024 * 1024);
    double GoS = ceil(poidsFlechetteGO / timeS);

    cout << "\tsucces = " << isOk;
    cout << "\t" << timeS << " [s]";
    cout << "\t" << nbDarBySeconde << " [dar/s]";
    cout << "\t" << GoS << " [GO/s] (register)";
    }

/*--------------------------------------*\
 |*		use		 	*|
 \*-------------------------------------*/

/**
 * ajuster si trop grand ou trop petit
 */
entier MontecarloUseTools::nbDarTotalUse()
    {
#ifdef DAR_INT
    int nbDar = Limits::MAX_INT ;
    return nbDar;
#endif

#ifdef DAR_LONG
    long nbDar = ((long)Limits::MAX_INT) *300;	// casting en long avant multiplication
    return nbDar;
#endif

    assert(false);	//ne doit jamais arriver ici
    }

/*--------------------------------------*\
 |*		test		 	*|
 \*-------------------------------------*/

/**
 * ajuster si trop grand ou trop petit
 *
 * Warning:
 * 		Comme les grids ne soint pas optimum, on doit prendre moins de dar que dans le cas du use qui emploie une grid plus optimum.
 * 		On voit une nouvelle fois, l'importance du choix de la grid
 */
entier MontecarloUseTools::nbDarTotalTest()
    {
#ifdef DAR_INT
    int nbDar = Limits::MAX_INT ;
    return nbDar;
#endif

#ifdef DAR_LONG
    long nbDar = ((long)Limits::MAX_INT) *4;	// casting en long avant multiplication
    return nbDar;
#endif

    assert(false);	//ne doit jamais arriver ici

    // Timeout:
    //
    //	Il y a un timeout de 2s sur le gpu sur lequel est connecter un ecran, normalemnet le device 0.
    //	Il n'y a aucun timeout sur les devices sur lesquels aucun ecran n'est connecter.
    //
    // 	Raison:
    //
    //		le driver coupe les kernels cuda si ceux-ci sont trop long,
    //		pour laisser le gpu faire son travail initial :
    //		afficher de l'information sur l ecran.
    //
    // Conclusion:
    //
    //	(C1) Ajuster le nombre de flechette pour ne passer depasser le timeout de 2s.
    //	     Au lieu de travailler sous la forme:
    //
    //			Limits::MAX_LONG / 100000;
    //
    //	     Travailler plutot sous la forme
    //
    //			((long)Limits::MAX_INT )*10; // casting en long pour que le * se fasse en long
    //
    //	(C2) Changer de device, et trouvez un surlequel il n'y a pas d' ecran, donc pas de timeout.
    //	     Aller a cet effet dans la methode main.
    //
    // Conseil:
    //
    // 	Depassez le type int, mais ne mettez pas trop de flechette,
    //	pour ne pas que les tests unitaires ne prennent trop de temps!
    //
    //	Rappel : un test unitaire doit etre raisonablement assez rapide,
    //		 sinon on ne le lance jamais, ce qui n'est pas le but!
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
