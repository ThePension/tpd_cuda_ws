#include "00_pi_tools.h"

#include <iostream>
#include "ChronoFactory.h"
#include "Maths.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

double fpi(double x)
    {
    return 4 / (1 + x * x);
    }

bool isAlgoPI_OK(AlgoPI algoPI , int n , string title)
    {
    cout << endl << endl << "[" << title << " running ...]" << endl;
    cout << "\tn=" << n << endl;

    Chrono* ptrChrono = ChronoFactory::create();
    double piHat = algoPI(n);
    ptrChrono->stop();

    cout.precision(8);
    cout << "\tPi hat  = " << piHat << endl;
    cout << "\tPi true = " << PI << endl;

    bool isOk = Maths::isEquals(piHat, PI, 1e-6);
    cout << "\tisOk = " << isOk << endl;

    cout.precision(3);
    cout<<"\ttime : "<<*ptrChrono<<endl;
    cout << endl;

    delete ptrChrono;

    return isOk;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

