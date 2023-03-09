#include <iostream>
#include <stdlib.h>

using std::cerr;
using std::cout;
using std::endl;

#include "Limits.h"
#include "ChronoFactory.h"

// ReductionTools add
#include "UseReductionAddIntI.h"
#include "UseReductionAddIntII.h"

// ReductionTools generic
#include "UseReductionIntI.h"
#include "UseReductionIntII.h"

#include "UseReductionLongII.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int mainUse()
    {
    Chrono* ptrChrono = ChronoFactory::create();

    const int IS_VERBOSE = true;

    // Commenter ce dont vous n'avez pas besoin ci-dessous

    bool isOk = true;

// reductiontools
	{
	// add
	UseReductionAddIntI useReductionAddIntI(IS_VERBOSE);
	UseReductionAddIntII useReductionAddIntII(IS_VERBOSE);

	isOk &= useReductionAddIntI.isOk(IS_VERBOSE);
	isOk &= useReductionAddIntII.isOk(IS_VERBOSE);

	// generic
	UseReductionIntI useReductionIntI(IS_VERBOSE);
	UseReductionIntII useReductionIntII(IS_VERBOSE);

	isOk &= useReductionIntI.isOk(IS_VERBOSE);
	isOk &= useReductionIntII.isOk(IS_VERBOSE);

	// long
	UseReductionLongII useReductionLongII(IS_VERBOSE);

	isOk &= useReductionLongII.isOk(IS_VERBOSE);
	}

    ptrChrono->stop();

    cout << endl << endl;
    cout << "mainCore :" << *ptrChrono << endl;
    cout << "mainCore : ";
    if (isOk)
	{
	cout << "SUCCESS, Congratulation!";
	}
    else
	{
	cerr << "FAILED, sorry!";
	}
    cout << endl << endl;

    delete ptrChrono;

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

