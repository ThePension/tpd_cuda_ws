#include "AddArrayUse.h"

#include "ArrayTools.h"
#include "AddArray.h"
#include "Limits.h"

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

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

static const int N = 9;

/*--------------------------------------*\
|*		Constructor		*|
 \*-------------------------------------*/

AddArrayUse::AddArrayUse() : //
	grid(createGrid()), //
	n(N)
    {
    this->ptrV1 = ArrayTools::createV1(n);
    this->ptrV2 = ArrayTools::createV2(n);
    this->ptrW = new float[n];

    this->ptrAddArray = new AddArray(grid, ptrV1, ptrV2, ptrW, n);
    }

AddArrayUse::~AddArrayUse()
    {
    delete ptrAddArray;

    delete[] ptrV1;
    delete[] ptrV2;
    delete[] ptrW;
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

bool AddArrayUse::isOk()
    {
    this->ptrAddArray->run();

    bool isOk = ArrayTools::isAddVector_Ok(ptrV1, ptrV2, ptrW, n);

    ArrayTools::print(ptrV1, n);
    ArrayTools::print(ptrV2, n);
    cout << "--------------------------------------------------------------------" << endl;
    ArrayTools::print(ptrW, n);
    cout << endl;

    cout << "[AddArray] : entrelacement : ";

    if (isOk)
	{
	cout << "Success!" << endl << endl;
	}
    else
	{
	cerr << "Failed!" << endl << endl;
	}

    return isOk;
    }

/*--------------------------------------*\
|*		Private			*|
 \*-------------------------------------*/

/**
 * static
 */
Grid AddArrayUse::createGrid()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    dim3 dg(MP * 2, 3, 1);
    dim3 db(CORE_MP, 2, 1); // produit <=1024
    Grid grid(dg, db);

    return grid;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
