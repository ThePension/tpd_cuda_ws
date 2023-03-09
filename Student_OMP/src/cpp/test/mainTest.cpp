#include <stdlib.h>
#include <iostream>

#include "CppTest.h"
#include "Folders.h"

#include "TestHello.h"
#include "TestPi.h"
#include "Chrome.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest(void)
    {
    Test::Suite testSuite;

    testSuite.add(std::auto_ptr < Test::Suite > (new TestHello()));
    testSuite.add(std::auto_ptr < Test::Suite > (new TestPi()));

    // run
	{
	string folder = "./out";
	string title = "testAll";
	string fileHTML = title + ".html";

	Folders::mkdirP(folder);

	int result = CppTest::run(folder, fileHTML, title, testSuite, OutputType::HTML); // HTML CONSOLE

	Chrome::showHTML(folder, fileHTML);// to be commented if OutputType::CONSOLE

	return result;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

