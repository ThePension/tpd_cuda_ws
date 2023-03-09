#include <iostream>
#include <stdlib.h>

using std::cerr;
using std::cout;
using std::endl;

#include "Limits.h"
#include "ChronoFactory.h"

// Array
#include "AddArrayUse.h"
#include "AddArrayUse11.h"

// Slice
#include "SliceGmHostUse.h"
#include "SliceGmUse.h"
#include "SliceSmUse.h"

// Montecarlo
#include "MontecarloUse.h"
#include "MontecarloMultiUse_thread.h"
#include "MontecarloMultiUse_stream.h"

// Vector
#include "AddVectorUse.h"
#include "AddVectorBistreamUse.h"
#include "AddVectorTristreamUse.h"
#include "VectorTools.h"

/*----------------------------------------------------------------------*\
 |*			Imported 					*|
 \*---------------------------------------------------------------------*/

extern bool addScalar_procedurale();
extern bool addScalar_objet();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int mainUse()
    {
    Chrono* ptrChrono = ChronoFactory::create();

    const int IS_VERBOSE = true;
    bool isOk = true;

    // Commenter ce dont vous n'avez pas besoin ci-dessous

    // hello
//	{
//	isOk &= addScalar_procedurale();
//	isOk &= addScalar_objet();
//	}

    // Array
	{
//	AddArrayUse addArrayUse;
//	AddArrayUse11 addArrayUse11;

//	isOk &= addArrayUse.isOk();
//	isOk &= addArrayUse11.isOk();
	}

    // Slice
	{
	SliceGmHostUse sliceGmHostUse(IS_VERBOSE);
//	SliceGmUse sliceGmUse(IS_VERBOSE);
//	SliceSmUse sliceSmUse(IS_VERBOSE);
//
	isOk &= sliceGmHostUse.isOk(IS_VERBOSE);
//	isOk &= sliceGmUse.isOk(IS_VERBOSE);
//	isOk &= sliceSmUse.isOk(IS_VERBOSE);
	}

    // Montecarlo
	{
//	for (float h = 4; h <= 10; h = h + 1)
//	    {
//	    MontecarloUse montecarloUse(IS_VERBOSE, h);
//	    isOk &= montecarloUse.isOk(IS_VERBOSE);
//	    }
//
//	cout << endl;
//
//	for (float h = 4; h <= 10; h = h + 1)
//	    {
//	    MontecarloMultiUse_thread montecarloMultiUse(IS_VERBOSE, h);
//	    isOk &= montecarloMultiUse.isOk(IS_VERBOSE);
//	    }
//
//	cout << endl;
//
//	for (float h = 4; h <= 10; h = h + 1)
//	    {
//	    MontecarloMultiUse_stream montecarloMultiUse(IS_VERBOSE, h);
//	    isOk &= montecarloMultiUse.isOk(IS_VERBOSE);
//	    }
	}

    // Vector
	{
//	AddVectorUse addVectorUse(IS_VERBOSE);
//	AddVectorBistreamUse addVectorBistreamUse(IS_VERBOSE);
//
//	isOk &= addVectorUse.isOk(false);
//	isOk &= addVectorBistreamUse.isOk(false);

// tristream : debug
//	    {
//	    int nbSlice = 3; // Changer aussi n dans VectorTools:n(); // Contrainte : n%nbSlkice=0 (pour se faciliter la vie)
//
//	    AddVectorTristreamUse addVectorTristreamUse(nbSlice, !IS_VERBOSE);
//	    bool isOkSlice = addVectorTristreamUse.isOk(!false);
//	    cout << nbSlice << "\t" << isOkSlice << endl;
//
//	    isOk &= isOkSlice;
//	    }

// tristream : use1
//	for (int nbSlice = 3; nbSlice <= 15; nbSlice++)
//	    {
//	    AddVectorTristreamUse addVectorTristreamUse(nbSlice, IS_VERBOSE);
//	    bool isOkSlice = addVectorTristreamUse.isOk(false);
//	   // cout << nbSlice << "\t" << isOkSlice << endl;
//
//	    isOk &= isOkSlice;
//	    }

// tristream : use2
//	for (int nbSlice = 5; nbSlice <= 75; nbSlice += 5)
//	    {
//	    AddVectorTristreamUse addVectorTristreamUse(nbSlice, IS_VERBOSE);
//	    bool isOkSlice = addVectorTristreamUse.isOk(false);
//	    //cout << nbSlice << "\t" << isOkSlice << endl;
//
//	    isOk &= isOkSlice;
//	    }
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

