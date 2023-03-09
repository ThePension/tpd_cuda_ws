#include <stdlib.h>
#include <iostream>
#include "ChronoFactory.h"

using std::cerr;
using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern bool usePI(void);
extern bool useHello(void);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore(void)
    {
    Chrono* ptrChrono = ChronoFactory::create();

    bool isOk = true;
    isOk &= useHello();
    isOk &= usePI();

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

