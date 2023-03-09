#include "UseReductionIntI.h"

#include "ReductionIntI.h"
#include "PIntI.h"

#include "Maths.h"
#include "Hardware.h"
#include "Limits.h"

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

UseReductionIntI::UseReductionIntI(const Grid& grid , bool isVerbose) : //
	UseReductionInt(grid, isVerbose, new ReductionIntI(grid, &sum, isVerbose), new PIntI())

    {
    // rien
    }

UseReductionIntI::UseReductionIntI(bool isVerbose) : //
	UseReductionIntI(createGrid(PIntI()), isVerbose)
    {
    //rien
    }

UseReductionIntI::~UseReductionIntI()
    {
    // rien
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
