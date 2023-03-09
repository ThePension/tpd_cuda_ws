#include "UseReductionAddIntII.h"

#include "ReductionAddIntII.h"
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

UseReductionAddIntII::UseReductionAddIntII(const Grid& grid , bool isVerbose) : //
	UseReductionInt(grid, isVerbose, new ReductionAddIntII(grid, &sum, isVerbose), new PIntII())
    {
// rien
    }

UseReductionAddIntII::UseReductionAddIntII(bool isVerbose) : //
	UseReductionAddIntII(createGrid(PIntII()), isVerbose)
    {
    //rien
    }

UseReductionAddIntII::~UseReductionAddIntII()
    {
    // rien
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
