#pragma once

#include "Provider_uchar_A.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class VideoBaseProvider: public Provider_uchar_A
    {
	/*----------------------------------------------------------------------*\
		 |*			Constructeur 					*|
	 \*---------------------------------------------------------------------*/

    public:

	VideoBaseProvider(bool loadOnlyOneImage = false);

	virtual ~VideoBaseProvider();

	/*----------------------------------------------------------------------*\
	|*			Methode 					*|
	 \*---------------------------------------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual Grid grid();

	/**
	 * Override
	 */
	virtual Animable_I<uchar>* createAnimable(const Grid& grid , bool isVerbose = false);

	/*----------------------------------------------------------------------*\
	 |*			attribut 					*|
	 \*---------------------------------------------------------------------*/

    private:

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
