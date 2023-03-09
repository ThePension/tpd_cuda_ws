#include <iostream>

#include "GLUTWindowScene.h"
#include "GLUTWindowManagers.h"
#include "Args.h"

#include "SceneCubeCreator.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

void mainCore(const Args& args)
    {
    GLUTWindowManagers::init(args.argc, args.argv);

    SceneCubeCreator sceneCubeCreator;
    SceneCube* ptrScene = sceneCubeCreator.getScene();

    int w = 16 * 32 * 2;

    GLUTWindowScene window(ptrScene, "Tuto Cube 3D", w, w, 60, 60); // (w,h, px,py)

    GLUTWindowManagers::getInstance()->runALL(); // bloquant
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
