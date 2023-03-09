#include "UseReductionLongII.h"

#include "ReductionLongII.h"
#include "PLongII.h"

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

UseReductionLongII::UseReductionLongII(const Grid& grid , bool isVerbose) : //
	UseReductionLong(grid, isVerbose, new ReductionLongII(grid, &sum, isVerbose), new PLongII())
    {
   // rien
    }

UseReductionLongII::UseReductionLongII(bool isVerbose) : //
	UseReductionLongII(createGrid(PLongII()), isVerbose)
    {
    //rien
    }

UseReductionLongII::~UseReductionLongII()
    {
    // rien
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
