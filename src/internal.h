#pragma once

#ifndef PI
	#define PI 3.14159265358979323846f
#endif
#define EPSILON 0.001f
#define PHI 1.61803399f
#define HALF_PI 1.570796326794f
#define DEG_TO_RAD 0.0174532925f
#define RAD_TO_DEG 57.2957795131

#ifndef min
	#define min(x, y) (x < y ? x : y)
#endif
#ifndef max
	#define max(x, y) (x > y ? x : y);
#endif

// General math functions
static inline float 
clamp ( float val, float top, float bottom ) {
	return max(bottom, min(val, top));
}

static inline float 
lerp ( float x, float y, float t ) {
	return x + (( y - x ) * t);
}
