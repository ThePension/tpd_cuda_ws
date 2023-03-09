#include <iostream>

#include "SceneCubeCreator.h"

#include "RipplingProvider.h"
#include "MandelbrotProvider.h"

#include "RaytracingProviderGM.h"
#include "RaytracingProviderSM.h"
#include "RaytracingProviderCM.h"
#include "RaytracingProviderCM2SM.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

SceneCubeCreator::SceneCubeCreator()
    {
    createImages();
    createScene();
    }

SceneCubeCreator::~SceneCubeCreator()
    {
    delete ptrImage1;
    delete ptrImage2;
    delete ptrImage3;
    delete ptrImage4;
    delete ptrImage5;
    delete ptrImage6;

    delete ptrScene;
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

SceneCube* SceneCubeCreator::getScene()
    {
    return ptrScene;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void SceneCubeCreator::createImages()
    {
    ptrImage1 = RipplingProvider().createImageGL();
    ptrImage2 = MandelbrotProvider().createImageGL();

    ptrImage3 = RaytracingProviderGM().createImageGL();
    ptrImage4 = RaytracingProviderSM().createImageGL();
    ptrImage5 = RaytracingProviderCM().createImageGL();
    ptrImage6 = RaytracingProviderCM2SM().createImageGL();
    }

void SceneCubeCreator::createScene()
    {
    ptrScene = new SceneCube(ptrImage1, ptrImage2, ptrImage3, ptrImage4, ptrImage5, ptrImage6);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

