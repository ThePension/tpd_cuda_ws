#include "UseReductionAddIntI.h"

#include <iostream>
#include <iomanip>
#include <assert.h>

#include "PIntI.h"
#include "ReductionAddIntI.h"

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

UseReductionAddIntI::UseReductionAddIntI(const Grid& grid , bool isVerbose) : //
	UseReductionInt(grid , isVerbose ,new ReductionAddIntI(grid, &sum, isVerbose),  new PIntI())

    {
   // rien
    }

UseReductionAddIntI::UseReductionAddIntI(bool isVerbose) : //
	UseReductionAddIntI(createGrid(PIntI()), isVerbose)
    {
    //rien
    }

UseReductionAddIntI::~UseReductionAddIntI()
    {
   // rien
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
