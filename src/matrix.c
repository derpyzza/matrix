#include "matrix.h"

char* matrix_test_func() {
	return "Hello there, from matrix!";
}

float radians( float angle )
{
	return angle * MAT_PI / 180;
}

float degrees( float angle )
{
	return angle * 180 / MAT_PI;
}

float clamp( float val, float top, float bottom )
{
	return max(bottom, min(val, top));
}

float lerp( float x, float y, float t )
{
	return x + (( y - x ) * t);
}
