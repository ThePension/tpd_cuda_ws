#include <iostream>
#include <assert.h>

#include "AddScalar.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

bool addScalar_objet()
    {
    float a = 8;
    float b = 80;
    float sum;

    // Partie interessante GPGPU
	{
	AddScalar addScalar(a, b, &sum);
	addScalar.run();
	}

    cout << "\n[Hello : Host   side : addScalar object] " << a << " + " << b << " = " << sum << endl;
    assert(sum == a + b);
    bool isOk = (sum == a + b);

    return isOk;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

