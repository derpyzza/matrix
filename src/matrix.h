#pragma once

#include "matrix_types.h"

#ifndef bool
  typedef enum {
    false = 0,
    true = 1
  } bool;
#endif

#define _PI 3.14159265358979323846f

#ifndef min
static inline float min(float x, float y) { return (x < y ? x : y); }
#endif
#ifndef max
static inline float max(float x, float y) { return (x > y ? x : y); }
#endif

char* matrix_test_func();

// General math functions
static inline float radians( float angle ) {
	return angle * _PI / 180;
}
static inline float degrees( float angle ) {
	return angle * 180 / _PI;
}
static inline float clamp( float val, float top, float bottom ) {
	return max(bottom, min(val, top));
}
static inline float lerp( float x, float y, float t ) {
	return x + (( y - x ) * t);
}

// Vector functions
// Creation / Initialization
//
// === Vector 2 ===
//
vec2_u vec2_new(float x, float y);
vec2_u vec2_zero(void);
vec2_u vec2_one(void);
vec2_u vec2_left(void);
vec2_u vec2_right(void);
vec2_u vec2_up(void);
vec2_u vec2_down(void);
//
// === Vector 3 ===
//
vec3_u vec3_new(float x, float y, float z);
vec3_u vec3_zero(void);
vec3_u vec3_one(void);
/** @brief returns a upward facing vector */
vec3_u vec3_up(void);
/** @brief returns a downward facing vector */
vec3_u vec3_down(void);
/** @brief returns a leftward facing vector */
vec3_u vec3_left(void);
/** @brief returns a rightward facing vector */
vec3_u vec3_right(void);
/** @brief returns a forward facing vector */
vec3_u vec3_forward(void);
/** @brief returns a backward facing vector */
vec3_u vec3_backward(void);
// === Vector 4 ===
vec4_u vec4_new(float x, float y, float z, float w);
vec4_u vec4_zero(void);
vec4_u vec4_one(void);
vec4_u vec4_from_vec3(vec3_u v);
// Equality checks
// === Vector 3 ===
//
/** @brief Compares the given vectors for equality */
bool vec2_is_eq(vec2_u v1, vec2_u v2);
bool vec2_is_neq(vec2_u v1, vec2_u v2);
/** @brief Compares the given vectors for equality */
bool vec3_is_eq(vec3_u v1, vec3_u v2);
bool vec3_is_neq(vec3_u v1, vec3_u v2);
bool vec4_is_eq(vec4_u v1, vec4_u v2);
bool vec4_is_neq(vec4_u v1, vec4_u v2);
//
// Basic Arithmetic Operations
//
vec2_u vec2_add(vec3_u v1, vec3_u v2);
vec2_u vec2_sub(vec2_u v1, vec2_u v2);
vec2_u vec2_div(vec2_u v1, vec2_u v2);
vec2_u vec2_cross(vec2_u v1, vec2_u v2);
vec2_u vec2_scale(vec3_u vec1, float scalar);
vec2_u vec2_neg(vec3_u v);
/** @brief returns a vector that is the product of two vectors
 * not at all useful geometrically, but good for when you're using
 * vectors as a three dimensional array;
 */
vec2_u vec2_mul(vec2_u v1, vec2_u v2);
vec2_u vec2_lerp(vec2_u v1, vec2_u v2, float t);
vec2_u vec2_length_squared(vec2_u v);
vec2_u vec2_normalize(vec2_u v);
float vec2_length(vec2_u v);
float vec2_dot(vec2_u v1, vec2_u v2);

vec3_u vec3_add(vec3_u v1, vec3_u v2);
vec3_u vec3_sub(vec3_u v1, vec3_u v2);
vec3_u vec3_div(vec3_u v1, vec3_u v2);
vec3_u vec3_cross(vec3_u v1, vec3_u v2);
vec3_u vec3_scale(vec3_u vec1, float scalar);
vec3_u vec3_neg(vec3_u v);
vec3_u vec3_mul(vec3_u v1, vec3_u v2);
vec3_u vec3_lerp(vec3_u v1, vec3_u v2, float t);
vec3_u vec3_length_squared(vec3_u v);
vec3_u vec3_normalize(vec3_u v);
float vec3_dot(vec3_u v1, vec3_u v2);
float vec3_length(vec3_u v);

vec4_u vec4_add(vec4_u v1, vec4_u v2);
vec4_u vec4_sub(vec4_u v1, vec4_u v2);
vec4_u vec4_div(vec4_u v1, vec4_u v2);
vec4_u vec4_cross(vec4_u v1, vec4_u v2);
vec4_u vec4_scale(vec4_u vec1, float scalar);
vec4_u vec4_neg(vec4_u v);
vec4_u vec4_mul(vec4_u v1, vec4_u v2);
vec4_u vec4_lerp(vec4_u v1, vec4_u v2, float t);
vec4_u vec4_length_squared(vec4_u v);
vec4_u vec4_normalize(vec4_u v);
float vec4_length(vec4_u v);
float vec4_dot(vec4_u v1, vec4_u v2);

/* === 3x3 MATRIX FUNCTIONS === */
mat3_u mat3_new(float data[9]);
mat3_u mat3_zero(void);
// Returns the identity matrix
mat3_u mat3_id(void);
mat4_u mat4_new(float data[16]);
mat4_u mat4_zero(void);
mat4_u mat4_id(void);
mat4_u mat4_scale(mat4_u matrix, vec3_u scale);
mat4_u mat4_mul(mat4_u m1, mat4_u m2);
mat4_u mat4_translate(mat4_u m, vec3_u v);
mat4_u mat4_rot(mat4_u m, float rad, vec3_u axis);
mat4_u mat4_rotx(mat4_u m, float rad);
mat4_u mat4_roty(mat4_u m, float rad);
mat4_u mat4_rotz(mat4_u m, float rad);
mat4_u persp(float fov, float near, float far, float ratio);
mat4_u ortho(float left, float right, float bottom, float top, float near, float far);
mat4_u look_at(vec3_u pos, vec3_u target, vec3_u up);
quat quat_id(void);
