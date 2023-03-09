#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

#include "CppTest.h"
#include "cudas.h"
#include "Folders.h"
#include "Chrome.h"

#include "Videos.h"

#include "TestVideoBase.h"
#include "TestVideoTextureGM.h"
#include "TestVideoTextureCuarray.h"
#include "TestVideoSurface.h"

//#include "TestConvolutionGauss.h"
//#include "TestConvolutionTexGauss.h"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

using Test::Suite;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest()
    {
    Videos::preloadONE();

    Suite testSuite;

    // Video
	{
	testSuite.add(std::auto_ptr < Suite > (new TestVideoBase()));
	testSuite.add(std::auto_ptr < Suite > (new TestVideoTextureGM()));
	testSuite.add(std::auto_ptr < Suite > (new TestVideoTextureCuarray()));
	testSuite.add(std::auto_ptr < Suite > (new TestVideoSurface()));
	}

    // Convolution
//	{
//	testSuite.add(std::auto_ptr < Suite > (new TestConvolutionGauss));
//	testSuite.add(std::auto_ptr < Suite > (new TestConvolutionTexGauss));
//	}

// run
	{
	string folder = "./out";
	string title = "testAll"; // see above, title list
	string fileHTML = title + ".html";

	Folders::mkdirP(folder);

	int result = CppTest::run(folder, fileHTML, title, testSuite, OutputType::HTML); // HTML CONSOLE

	Chrome::showHTML(folder, fileHTML); // to be commented if OutputType::CONSOLE

	return result;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

