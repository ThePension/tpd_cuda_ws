#include "SliceNumber.h"

#include "Limits.h"

#include <iostream>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/**
 * <pre>
 * Warning:
 *
 * 	Pas trop de slice sinon on atteind les limtes du type float/double.
 * 	Les bases des rectangles deviennent trop petites.
 *
 * Example:
 *
 * 	int nbSlice = Limits::MAX_INT / 2
 *
 * 	vous donnera par exemple un resultat moins precis que:
 *
 * 	int nbSlice = Limits::MAX_INT / 100;
 * </pre>
 */
int SliceNumber::nbSlice()
    {
    return Limits::MAX_INT / 100;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
