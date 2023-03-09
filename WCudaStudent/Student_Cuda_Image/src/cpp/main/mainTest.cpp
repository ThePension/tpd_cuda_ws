#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

#include "CppTest.h"
#include "cudas.h"
#include "Folders.h"
#include "Chrome.h"

#include "TestRippling.h"
#include "TestMandelbrot.h"

#include "TestRaytracingGM.h"
#include "TestRaytracingCM.h"
#include "TestRaytracingSM.h"
#include "TestRaytracingCM2SM.h"

using std::string;
using std::cout;
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
    Suite testSuite;

    // Rippling
	{
	testSuite.add(std::auto_ptr < Suite > (new TestRippling()));
	}

// Mandelbrot
	{
	testSuite.add(std::auto_ptr < Suite > (new TestMandelbrot));
	}

// Raytracing
	{
	testSuite.add(std::auto_ptr < Suite > (new TestRaytracingGM));
	testSuite.add(std::auto_ptr < Suite > (new TestRaytracingCM));
	testSuite.add(std::auto_ptr < Suite > (new TestRaytracingSM));
	testSuite.add(std::auto_ptr < Suite > (new TestRaytracingCM2SM));
	}

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

