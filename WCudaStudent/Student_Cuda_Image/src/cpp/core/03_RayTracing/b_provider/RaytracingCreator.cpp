#include "RaytracingCreator.h"

#include "Grid.h"
#include "Hardware.h"

#include <assert.h>

#include "memoryType.h"
#include "Raytracing.h"
#include "nbSphere.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

Raytracing* RaytracingCreator::createGM(const Grid& grid , bool isVerbose)
    {
    return create(MemoryType::GM, grid, isVerbose);
    }

Raytracing* RaytracingCreator::createCM(const Grid& grid , bool isVerbose)
    {
    return create(MemoryType::CM, grid, isVerbose);
    }

Raytracing* RaytracingCreator::createSM(const Grid& grid , bool isVerbose)
    {
    return create(MemoryType::SM, grid, isVerbose);
    }

Raytracing* RaytracingCreator::createCM2SM(const Grid& grid , bool isVerbose)
    {
    return create(MemoryType::CM2SM, grid, isVerbose);
    }

/*--------------------------------------*\
|*		private		*|
 \*-------------------------------------*/

#include "ChronoFactory.h"

Raytracing* RaytracingCreator::create(MemoryType memoryType , const Grid& grid , bool isVerbose)
    {
// Animation;
    float dt = 2 * PI / 1000;

// Dimension
    int w = 16 * 80;
    int h = 16 * 60;

    // Chrono* ptrChrono = ChronoFactory::create();
    Raytracing* ptrRaytracing = new Raytracing(grid, w, h, dt, isVerbose, NB_SPHERE, memoryType); // NB_SPHERE define "nbSphere.h"
    // ptrChrono->stop();
    // cout << "[RaytracingCreator] : " << *ptrChrono << endl;

    return ptrRaytracing;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
