#pragma once

#include "matrix_types.h"
#ifdef MATRIX_DEBUG_FUNCTIONS
	#include "matrix_debug/matrix_debug.h"
#endif

#define MAT_PI 3.14159265358979323846f

#ifndef min
static inline float min(float x, float y) { return (x < y ? x : y); }
#endif
#ifndef max
static inline float max(float x, float y) { return (x > y ? x : y); }
#endif

char* matrix_test_func(void);

// General math functions
float radians( float angle );
float degrees( float angle );
float clamp( float val, float top, float bottom );
float lerp( float x, float y, float t );

// Data type creation functions
static inline 
vec2_u vec2_new(float x, float y)
{
	return (vec2_u){{x, y}};
}

static inline 
vec3_u vec3_new(float x, float y, float z)
{
	return (vec3_u){{x, y, z}}; 
}

static inline 
vec4_u vec4_new(float x, float y, float z, float w)
{
	return (vec4_u){{x, y, z, w}};
}

static inline 
mat3_u mat3_new( float data[9] )
{
  return (mat3_u) {{
    data[0],  data[1], data[2],
    data[3],  data[4], data[5],
    data[6],  data[6], data[8]
  }};
}

static inline
mat4_u 	mat4_new( float data[16] )
{
   return (mat4_u) {{
		 data[ 0],  data[ 1], data[ 2], data[ 3],
		 data[ 4],  data[ 5], data[ 6], data[ 7],
		 data[ 8],  data[ 9], data[10], data[11],
		 data[12],  data[13], data[14], data[15]
	 }};
}

// Vector functions
// Creation / Initialization
//
// === Vector 2 ===
//

/** @brief returns an empty vector */
vec2_u vec2_zero(void);
/** @brief returns a unit vector */
vec2_u vec2_one(void);
/** @brief returns a leftward facing unit vector */
vec2_u vec2_left(void);
/** @brief returns a rightward facing unit vector */
vec2_u vec2_right(void);
/** @brief returns a upward facing unit vector */
vec2_u vec2_up(void);
/** @brief returns a downward facing unit vector */
vec2_u vec2_down(void);
//
// === Vector 3 ===
//

/** @brief returns an empty vector */
vec3_u vec3_zero(void);
/** @brief returns a unit vector */
vec3_u vec3_one(void);
/** @brief returns a upward facing unit vector */
vec3_u vec3_up(void);
/** @brief returns a downward facing unit vector */
vec3_u vec3_down(void);
/** @brief returns a leftward facing unit vector */
vec3_u vec3_left(void);
/** @brief returns a rightward facing unit vector */
vec3_u vec3_right(void);
/** @brief returns a forward facing unit vector */
vec3_u vec3_forward(void);
/** @brief returns a backward facing unit vector */
vec3_u vec3_backward(void);

// === Vector 4 ===
/** @brief returns an empty vector */
vec4_u vec4_zero(void);
/** @brief returns a unit vector */
vec4_u vec4_one(void);
/** @brief returns a homogenous vector, where w = 1 */
vec4_u vec4_from_vec3(vec3_u v);

// Equality checks
// === Vector 3 ===
//
/** @brief Compares the given vectors for equality */
int vec2_is_eq(vec2_u v1, vec2_u v2);
int vec2_is_neq(vec2_u v1, vec2_u v2);
/** @brief Compares the given vectors for equality */
int vec3_is_eq(vec3_u v1, vec3_u v2);
int vec3_is_neq(vec3_u v1, vec3_u v2);
int vec4_is_eq(vec4_u v1, vec4_u v2);
int vec4_is_neq(vec4_u v1, vec4_u v2);
//
// Basic Arithmetic Operations
//

/** @brief adds two vectors and returns the result */
vec2_u vec2_add(vec2_u v1, vec2_u v2);
/** @brief subtracts two vectors and returns the result */
vec2_u vec2_sub(vec2_u v1, vec2_u v2);
/** @brief divides two vectors and returns the result */
vec2_u vec2_div(vec2_u v1, vec2_u v2);
/** @brief returns the cross product of two vectors */
vec2_u vec2_cross(vec2_u v1, vec2_u v2);
/** @brief scales a given vector by a scalar amount, and returns the result */
vec2_u vec2_scale(vec3_u vec1, float scalar);
/** @brief inverts the values of a given vector */
vec2_u vec2_neg(vec3_u v);
/** @brief returns a vector that is the product of two vectors
 *
 * @comment not at all useful geometrically, but good for when you're using
 * vectors as an array;
 */
vec2_u vec2_mul(vec2_u v1, vec2_u v2);
/** @brief lerps between the given vectors by t, and returns the result */
vec2_u vec2_lerp(vec2_u v1, vec2_u v2, float t);
/** @brief returns the squared length of a given vector */
vec2_u vec2_length_squared(vec2_u v);
/** @brief normalizes and returns a given vector */
vec2_u vec2_normalized(vec2_u v);
/** @brief returns the length of a vector */
float vec2_length(vec2_u v);
/** @brief returns the dot product of two vectors */
float vec2_dot(vec2_u v1, vec2_u v2);

/** @brief adds two vectors and returns the result */
vec3_u vec3_add(vec3_u v1, vec3_u v2);
/** @brief subtracts two vectors and returns the result */
vec3_u vec3_sub(vec3_u v1, vec3_u v2);
/** @brief divides two vectors and returns the result */
vec3_u vec3_div(vec3_u v1, vec3_u v2);
/** @brief returns the cross product of two vectors */
vec3_u vec3_cross(vec3_u v1, vec3_u v2);
/** @brief scales a given vector by a scalar amount, and returns the result */
vec3_u vec3_scale(vec3_u vec1, float scalar);
/** @brief inverts the values of a given vector */
vec3_u vec3_neg(vec3_u v);
/** @brief returns a vector that is the product of two vectors
 *
 * @comment not at all useful geometrically, but good for when you're using
 * vectors as an array;
 */
vec3_u vec3_mul(vec3_u v1, vec3_u v2);
/** @brief lerps between the given vectors by t, and returns the result */
vec3_u vec3_lerp(vec3_u v1, vec3_u v2, float t);
/** @brief returns the squared length of a given vector */
vec3_u vec3_length_squared(vec3_u v);
/** @brief normalizes and returns a given vector */
vec3_u vec3_normalized(vec3_u v);
/** @brief returns the dot product of two vectors */
float vec3_dot(vec3_u v1, vec3_u v2);
/** @brief returns the length of a vector */
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
vec4_u vec4_normalized(vec4_u v);
/** @brief returns the result of multiplying a matrix with a vector 4 */
vec4_u vec4_mul_mat4(vec4_u v, mat4_u m);
float vec4_length(vec4_u v);
float vec4_dot(vec4_u v1, vec4_u v2);

/* === 3x3 MATRIX FUNCTIONS === */
mat3_u mat3_new(float data[9]);
mat3_u mat3_zero(void);
// Returns the identity matrix
mat3_u mat3_id(void);

mat4_u mat4_new(float data[16]);
mat4_u mat4_zero(void);
mat4_u mat4_one(void);
mat4_u mat4_float(float);
mat4_u mat4_id(void);
mat4_u mat4_scale(mat4_u matrix, vec3_u scale);
mat4_u mat4_scale_matrix(mat4_u matrix, vec3_u scale);
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
