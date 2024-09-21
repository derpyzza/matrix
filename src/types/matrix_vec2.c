#include "../matrix.h"
#include <math.h>

// Creation / Initialization
vec2_u vec2_zero(void) {
	return vec2_new(0, 0);
}
vec2_u vec2_one(void) { 
	return vec2_new(1, 1);
}
vec2_u vec2_left(void) {
	return vec2_new(-1, 0);
}
vec2_u vec2_right(void) {
	return vec2_new(1, 0);
}
vec2_u vec2_up(void) {
	return vec2_new(0, -1);
}
vec2_u vec2_down(void) {
	return vec2_new(0, 1);
}

// Equality checks
/** @brief Compares the given vectors for equality */
int vec2_is_eq( vec2_u v1, vec2_u v2 ) {
	return ( v1.x == v2.x && v1.y == v2.y );
}
/** @brief Compares the given vectors for equality */
int vec2_is_neq( vec2_u v1, vec2_u v2 ) {
	return ( v1.x != v2.x || v1.y != v2.y );
}

vec2_u vec2_add(vec2_u v1, vec2_u v2) {
	return vec2_new(v1.x + v2.x, v1.y + v2.y);
}
vec2_u vec2_sub(vec2_u v1, vec2_u v2) {
	return vec2_new(v1.x - v2.x, v1.y - v2.y);
}
vec2_u vec2_div(vec2_u v1, vec2_u v2) {
	return vec2_new(v1.x / v2.x, v1.y / v2.y);
}
/** @brief returns a vector that is the product of two vectors
 * not at all useful geometrically, but good for when you're using
 * vectors as a three dimensional array;
 */
vec2_u vec2_mul(vec2_u v1, vec2_u v2) {
	return vec2_new(v1.x * v2.x, v1.y * v2.y);
}
vec2_u vec2_scale(vec3_u vec1, float scalar) {
	return vec2_new(vec1.x * scalar, vec1.y * scalar);
}
vec2_u vec2_neg( vec3_u v ) {
	return vec2_new(
		v.x ? v.x * -1 : v.x, 
		v.y ? v.y * -1 : v.y );
}
vec2_u vec2_lerp( vec2_u v1, vec2_u v2, float t ) {
	vec2_u v;
	v.x = lerp(v1.x, v2.x, t);
	v.y = lerp(v1.y, v2.y, t);
	return v;
}

vec2_u vec2_length_squared ( vec2_u v ) {
	return vec2_new(v.x * v.x, v.y * v.y);
}

float vec2_length( vec2_u v ) {
	return sqrtf( v.x * v.x + v.y * v.y );
}

vec2_u vec2_normalized(vec2_u v) {
	const float len = vec2_length(v);
	v.x /= len;
	v.y /= len;

	return v;
}

