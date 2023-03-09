#include <iostream>
#include <assert.h>

#include "Args.h"
#include "LaunchMode.h"
using namespace cpu;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern int mainImage(const Args& args);
extern int mainAnimable();

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static int work(const Args& args , const LaunchMode& launchMode);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

int main(int argc , char** argv)
    {
    Args args(argc, argv);

    LaunchMode launchMode = LaunchMode::IMAGE; // IMAGE ANIMABLE

    return work(args, launchMode);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int work(const Args& args , const LaunchMode& launchMode)
    {
    switch (launchMode)
	{
    case IMAGE:
	return mainImage(args); // Bloquant, Tant qu'une fenetre est ouverte
    case ANIMABLE:
	return mainAnimable();
    default:
	assert(false);
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

