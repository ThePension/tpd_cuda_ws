#include "SliceSmUse.h"

#include "SliceSM.h"
#include "SliceNumber.h"

#include "Maths.h"
#include "Hardware.h"

#include <iostream>
#include <iomanip>
#include <assert.h>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::setprecision;

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeurs		*|
 \*-------------------------------------*/

/**
 * db power 2
 */
SliceSmUse::SliceSmUse(const Grid& grid , bool isVerbose) : //
	nbSlice(SliceNumber::nbSlice()), //
	grid(grid), //
	piHat(-1)
    {
    this->ptrRunnableGPU = new SliceSM(grid, nbSlice, &this->piHat, isVerbose);

    assert(filter(grid));
    }

SliceSmUse::SliceSmUse(bool isVerbose) :
	SliceSmUse(createGrid(), isVerbose)
    {
    // rien
    }

SliceSmUse::~SliceSmUse()
    {
    delete ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/**
 * override
 */
bool SliceSmUse::filter(const Grid& grid)
    {
    return Use_I::filter(grid) //
    && Maths::isPower2(grid.threadByBlock());
    }

/*--------------*\
|*	isOk	*|
 \*-------------*/

/**
 * override
 */
bool SliceSmUse::isOk(bool isVerbose)
    {
    this->ptrRunnableGPU->run();

    bool isOk = Maths::isEquals(this->piHat, PI, 1e-4); // Si certains de vos tests unitaires manquent de precision, passer a 1e-2 (non associtaivite de l'addition)

    if (isVerbose)
	{
	string title = "[" + ptrRunnableGPU->getTitle() + "]";
	cout << setprecision(4);
	cout << endl;
	cout << title << " : PI hat = " << piHat << endl;
	cout << title << " : PI     = " << PI << endl;
	cout << title << " : ";

	if (isOk)
	    {
	    cout << "Success!" << endl;
	    }
	else
	    {
	    cerr << "Failed!" << endl;
	    }
	}

    return isOk;
    }

/*--------------*\
|*	get	*|
 \*-------------*/

/**
 * override
 * Warning : It's a getter, the user is not responsible for deleting RunnableGPU_I*
 */
RunnableGPU_I* SliceSmUse::getRunnableGPU()
    {
    return this->ptrRunnableGPU;
    }

/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/

/**
 * static
 */
Grid SliceSmUse::createGrid()
    {
    const int MP = Hardware::getMPCount();

    // Contraintes :
    //	(C1) max(db.x*db.y*db.z)<=1024
    //	(C2) db power 2 (reduction)

    Grid grid; // TODO SliceSM
    assert(false); // to remove once coded

    return grid;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
