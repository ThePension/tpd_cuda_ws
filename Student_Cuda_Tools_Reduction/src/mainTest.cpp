#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>

#include "CppTest.h"
#include "cudas.h"
#include "Folders.h"
#include "Chrome.h"

// ReductionTools add
#include "TestReductionAddI.h"
#include "TestReductionAddII.h"

// ReductionTools generic
#include "TestReductionGenericI.h"
#include "TestReductionGenericII.h"

#include "TestReductionGenericLongII.h"

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

    // ReductionTools
	{
	// atomic
	testSuite.add(std::auto_ptr < Suite > (new TestReductionAddI()));
	testSuite.add(std::auto_ptr < Suite > (new TestReductionAddII()));

	// generic
	testSuite.add(std::auto_ptr < Suite > (new TestReductionGenericI()));
	testSuite.add(std::auto_ptr < Suite > (new TestReductionGenericII()));

	// long
	testSuite.add(std::auto_ptr < Suite > (new TestReductionGenericLongII()));
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

