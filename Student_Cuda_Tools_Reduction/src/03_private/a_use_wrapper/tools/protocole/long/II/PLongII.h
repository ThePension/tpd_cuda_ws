#pragma once

#include "PLong.h"

/*----------------------------------------------------------------------*\
 |*			Class	 					*|
 \*---------------------------------------------------------------------*/

class PLongII: public PLong
    {
	/*------------------------------------------------------------*\
        |*			Constructors 			      *|
	 \*------------------------------------------------------------*/

    public:

	PLongII();

	virtual ~PLongII();

	/*------------------------------------------------------------*\
        |*			Methodes 			      *|
	 \*------------------------------------------------------------*/

    public:

	/**
	 * override
	 */
	bool isSizeMaxOK(const Grid& grid);

	/**
	 * override
	 */
	int dgxMax() const;

	/**
	 * override
	 */
	long resultatTheorique(const Grid& grid);

	/*------------------------------------------------------------*\
        |*			Attributs			      *|
	 \*------------------------------------------------------------*/

    private:

	// Input

	// Tools

	// Output

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/