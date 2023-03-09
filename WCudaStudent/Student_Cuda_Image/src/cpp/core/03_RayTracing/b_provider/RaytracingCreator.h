#pragma once

#include "memoryType.h"
#include "Raytracing.h"
#include "Grid.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class RaytracingCreator
    {
    public:

	static Raytracing* createGM(const Grid& grid,bool isVerbose);
	static Raytracing* createCM(const Grid& grid,bool isVerbose);
	static Raytracing* createSM(const Grid& grid,bool isVerbose);
	static Raytracing* createCM2SM(const Grid& grid,bool isVerbose);

    private:

	static Raytracing* create(MemoryType memoryType,const Grid& grid,bool isVerbose);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

