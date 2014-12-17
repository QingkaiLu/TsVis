#ifndef _COMMON_HEADER_H_
#define _COMMON_HEADER_H_

#include"Config.h"
#include"cmath."


#if DOUBLE_PRECISION == 1
	typedef double Real;
#else
	typedef float Real;
#endif

typedef unsigned int	uint;

const Real PI = (Real)(4.0*atan(1.0));

const double EPS = 1.0e-6;

// Pre-declaration of classes so that can use pointers in header files
// without including corresponding .h, decreasing coupling of files
class Radian;
class Degree;
class Angle;


#endif