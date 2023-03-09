#include "UseReductionIntII.h"

#include "ReductionIntII.h"
#include "PIntII.h"

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

UseReductionIntII::UseReductionIntII(const Grid& grid , bool isVerbose) : //
	UseReductionInt(grid, isVerbose, new ReductionIntII(grid, &sum, isVerbose), new PIntII())
    {
    // rien
    }

UseReductionIntII::UseReductionIntII(bool isVerbose) : //
	UseReductionIntII(createGrid(PIntII()), isVerbose)

    {
    //rien
    }

UseReductionIntII::~UseReductionIntII()
    {
    // rien
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
