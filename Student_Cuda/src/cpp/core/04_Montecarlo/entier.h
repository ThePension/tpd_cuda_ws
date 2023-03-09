#pragma once

#include <iostream>
#include <assert.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*----------------------*\
 |*	public 		*|
 \*---------------------*/

// Choose one of the two (either/either):
#define DAR_INT
//#define DAR_LONG

/*----------------------*\
 |*	private 	*|
 \*---------------------*/

#ifdef DAR_INT
#define entier int
#endif

#ifdef DAR_LONG
#define entier long
#endif

static std::string entierToString()
    {
    #ifdef DAR_INT
    return "int";
    #endif

    #ifdef DAR_LONG
    return "long";
    #endif

    assert(false);// ne devrait jamais arriver
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

