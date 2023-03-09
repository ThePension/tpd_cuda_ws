#pragma once

#include <iostream>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*----------------------*\
 |*	public 		*|
 \*---------------------*/

// Choose one of the two (either/either):
//#define MANDELBROT_DOUBLE
#define MANDELBROT_FLOAT
//#define MANDELBROT_HALF

/*----------------------*\
 |*	private 	*|
 \*---------------------*/

// fp64 (float 64 bits)
#ifdef MANDELBROT_DOUBLE
#define real double
#endif

// fp32 (float 32 bits)
#ifdef MANDELBROT_FLOAT
#define real float
#endif

// fp16 (float 16 bits)
#ifdef MANDELBROT_HALF
#define real half
#endif

static std::string realToString()
    {
    #ifdef MANDELBROT_DOUBLE
   return "fp64";
   #endif

    #ifdef MANDELBROT_FLOAT
    return "fp32";
    #endif

    #ifdef MANDELBROT_HALF
    return "fp16";
    #endif
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

