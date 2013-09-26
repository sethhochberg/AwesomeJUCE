// this #define enables the following constants form math.h
#define _MATH_DEFINES_DEFINED
/*
#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402
#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401
*/
#include <math.h>

// Helper Functions ------------------------------------------------------------- //
// calcLogControl: accepts a float variable from 0.0 to 1.0
// returns a log version from 0.0 to 1.0
/* y = 0.5*log10(x) + 1.0
	|
1.0 |					*
	|		*
	|	*
	| *
	|*
	|*
0.0 ------------------------
	0.0					1.0
*/
inline float calcLogControl(float fVar)
{
	return fVar == 0.0 ? 0.0 : 0.5*log10(fVar) + 1.0;
}
// ----------------------------------------------------------------------------- //

// calcAntiLogControl: accepts a float variable from 0.0 to 1.0
// returns an anti-log version from 0.0 to 1.0
/* y = e^(2x-2)
	|
1.0 |					*
	|					*
	|				  *
	|				*
	|		*
	|*
0.0 ------------------------
	0.0					1.0
*/
inline float calcAntiLogControl(float fVar)
{
	return pow(10.0, 2.0*fVar - 2);
}
// ----------------------------------------------------------------------------- //

// calcInverseLogControl:accepts a float variable from 0.0 t0 1.0
// returns an anti-log version from 1.0 to 0.0
/* y = 0.5(1-x) + 1
	|
1.0 |*					
	|			*					
	|				*	  
	|				  *
	|					*
	|					*
0.0 ------------------------
	0.0					1.0
*/
inline float calcInverseLogControl(float fVar)
{
	return fVar == 1.0 ? 0.0 : 0.5*log10(1.0 - fVar) + 1.0;
}
// ----------------------------------------------------------------------------- //

// calcInverseAntiLogControl: accepts a float variable from 0.0 t0 1.0
// returns an anti-log version from 1.0 to 0.0
/* y = 10^(-2x) -- this is similar to e^(-5x) but clamps value to 0 at 1
	|
1.0 |*					
	|*		
	| *	
	|	*
	|		*
	|					*
0.0 ------------------------
	0.0					1.0
*/
inline float calcInverseAntiLogControl(float fVar)
{
	return pow((float)10.0, (float)-2.0*fVar);
}
// ----------------------------------------------------------------------------- //