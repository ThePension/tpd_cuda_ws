#include <iostream>
#include <limits.h>
#include "Limits.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

extern int mainCore(void);
extern int mainTest(void);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(void)
    {
    cout << "main" << endl;

    Limits::rappelTypeSize();

    const bool IS_TEST = false;
    return IS_TEST ? mainTest() : mainCore();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
