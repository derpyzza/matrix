#pragma once

#ifdef MATRIX_DEBUG_FUNCTIONS
	#include "matrix_debug.h"
#endif

#include "matrix_types.h"

#ifndef bool
	#include <stdbool.h>
#endif

static inline 
Vec2 vec2_new (float x, float y) {
	return (Vec2){x, y};
}

static inline 
Vec3 vec3_new (float x, float y, float z) {
	return (Vec3){x, y, z};
}

static inline 
Vec4 vec4_new (float x, float y, float z, float w) {
	return (Vec4){x, y, z, w};
}

static inline Mat2 
mat2_new ( float data[4] ) {
	return (Mat2) {{
		{ data[0], data[1] },
		{ data[2], data[3] },
	}};
}

static inline Mat3 
mat3_new ( float data[9] ) {
  return (Mat3) {{
    { data[0],  data[1], data[2] },
    { data[3],  data[4], data[5] },
    { data[6],  data[6], data[8] },
	}};
}

static inline Mat4 
mat4_new( float data[16] ) {
   return (Mat4) {{
		 { data[ 0],  data[ 1], data[ 2], data[ 3]},
		 { data[ 4],  data[ 5], data[ 6], data[ 7]},
		 { data[ 8],  data[ 9], data[10], data[11]},
		 { data[12],  data[13], data[14], data[15]}
	 }};
}

// VEC2 {{
// equality checks
bool vec2_is_eq  ( Vec2 a, Vec2 b );
bool vec2_is_neq ( Vec2 a, Vec2 b );

// basic elementwise arithmetic
Vec2 vec2_neg   ( Vec3 v );	// complement
Vec2 vec2_add   ( Vec2 a, Vec2 b );
Vec2 vec2_sub   ( Vec2 a, Vec2 b );
Vec2 vec2_div   ( Vec2 a, Vec2 b );
Vec2 vec2_mul   ( Vec2 a, Vec2 b );
Vec2 vec2_scale ( Vec3 v, float by );

// misc
Vec2  vec2_length_squared ( Vec2 v );
Vec2  vec2_normalized     ( Vec2 v );
float vec2_length         ( Vec2 v );
float vec2_dot            ( Vec2 a, Vec2 b );
Vec2  vec2_lerp           ( Vec2 a, Vec2 b, float t );
// }} VEC2


// VEC3 {{
// equality checks
bool vec3_is_eq  ( Vec3 a, Vec3 b ); 
bool vec3_is_neq ( Vec3 a, Vec3 b ); 

// basic elementwise arithmetic
Vec3 vec3_neg   ( Vec3 v ); // complement
Vec3 vec3_add   ( Vec3 a, Vec3 b );
Vec3 vec3_sub   ( Vec3 a, Vec3 b );
Vec3 vec3_div   ( Vec3 a, Vec3 b );
Vec3 vec3_mul   ( Vec3 a, Vec3 b );
Vec3 vec3_scale ( Vec3 v, float by );

// misc
Vec3  vec3_length_squared ( Vec3 v );
Vec3  vec3_normalized     ( Vec3 v );
float vec3_length         ( Vec3 v );
float vec3_dot            ( Vec3 a, Vec3 b );
Vec3  vec3_cross          ( Vec3 a, Vec3 b );
Vec3  vec3_lerp           ( Vec3 a, Vec3 b, float t );
// }} VEC3


// VEC4 {{
// equality checks
bool vec4_is_eq  ( Vec4 a, Vec4 b );
bool vec4_is_neq ( Vec4 a, Vec4 b );

// basic elementwise arithmetic
Vec4 vec4_neg   ( Vec4 v );
Vec4 vec4_add   ( Vec4 a, Vec4 b );
Vec4 vec4_sub   ( Vec4 a, Vec4 b );
Vec4 vec4_mul   ( Vec4 a, Vec4 b );
Vec4 vec4_div   ( Vec4 a, Vec4 b );
Vec4 vec4_scale ( Vec4 v, float by );

// misc
Vec4  vec4_length_squared ( Vec4 v );
Vec4  vec4_normalized     ( Vec4 v );
float vec4_length         ( Vec4 v );
float vec4_dot            ( Vec4 v );
Vec4  vec4_mul_mat4       ( Vec4 v, Mat4 m );
Vec4  vec4_lerp           ( Vec4 a, Vec4 b, float t );
// }} VEC4


// MAT4 {{
Mat4 mat4_scale     (Mat4 matrix, Vec3 scale);
Mat4 mat4_mul       (Mat4 m1, Mat4 m2);
Mat4 mat4_translate (Mat4 m, Vec3 v);

Mat4 mat4_rot  (Mat4 m, float rad, Vec3 axis);
Mat4 mat4_rotx (Mat4 m, float rad);
Mat4 mat4_roty (Mat4 m, float rad);
Mat4 mat4_rotz (Mat4 m, float rad);

Mat4 persp   (float fov, float near, float far, float ratio);
Mat4 ortho   (float left, float right, float bottom, float top, float near, float far);
Mat4 look_at (Vec3 pos, Vec3 target, Vec3 up);
// }} MAT4

//
// VECTOR CONSTANTS
//

#define VEC2_ZERO   (Vec2) {  0,  0 }
#define VEC2_ONE    (Vec2) {  1,  1 }
#define VEC2_LEFT   (Vec2) { -1,  0 }
#define VEC2_RIGHT  (Vec2) {  1,  0 }
#define VEC2_UP     (Vec2) {  0, -1 }
#define VEC2_DOWN   (Vec2) {  0,  1 }
#define VEC2_SET(x) (Vec2) {  x,  x }

#define VEC3_ZERO   (Vec3) {  0,  0,  0 }
#define VEC3_ONE    (Vec3) {  1,  1,  1 }
#define VEC3_UP     (Vec3) {  0, -1,  0 }
#define VEC3_DOWN   (Vec3) {  0,  1,  0 }
#define VEC3_LEFT   (Vec3) { -1,  0,  0 }
#define VEC3_RIGHT  (Vec3) {  1,  0,  0 }
#define VEC3_FRONT  (Vec3) {  0,  0,  1 }
#define VEC3_BACK   (Vec3) {  0,  0, -1 }
#define VEC3_SET(x) (Vec3) {  x,  x,  x }
#define VEC3_FROM_VEC2(v)  {  v.x, v.y, 0 }

#define VEC4_ZERO   (Vec4) {  0,  0,  0,  0 }
#define VEC4_ONE    (Vec4) {  1,  1,  1,  1 }
#define VEC4_LEFT   (Vec4) { -1,  0,  0,  1 }
#define VEC4_RIGHT  (Vec4) {  1,  0,  0,  1 }
#define VEC4_DOWN   (Vec4) {  0,  1,  0,  1 }
#define VEC4_UP     (Vec4) {  0, -1,  0,  1 }
#define VEC4_FRONT  (Vec4) {  0,  0,  1,  1 }
#define VEC4_BACK   (Vec4) {  0,  0, -1,  1 }
#define VEC4_SET(x) (Vec4) {  x,  x,  x,  x }
#define VEC4_FROM_VEC2(v) { v.x, v.y, 0, 1 }
#define VEC4_FROM_VEC3(v) {  v.x,  v.y,  v.z,  1 }


//
// MATRIX CONSTANTS
//

#define \
MAT2_ID (Mat2) {{ \
	{1, 0},                 \
	{0, 1}                  \
}}

#define \
MAT2_ZERO (Mat2) {{ \
	{0, 0},                   \
	{0, 0}                    \
}}

#define \
MAT2_ONE (Mat2) {{ \
	{1, 1},                 \
	{1, 1}                  \
}}

#define \
MAT2_SET(n) (Mat2) {{ \
	{n, n},                 \
	{n, n}                  \
}}



#define \
MAT3_ID (Mat3) {{ \
	{1, 0, 0},              \
	{0, 1, 0},              \
	{0, 0, 1}               \
}}

#define \
MAT3_ZERO (Mat3) {{ \
	{0, 0, 0},                \
	{0, 0, 0},                \
	{0, 0, 0}                 \
}}

#define \
MAT3_ONE (Mat3) {{ \
	{1, 1, 1},              \
	{1, 1, 1},              \
	{1, 1, 1}               \
}}

#define \
MAT3_SET(n) (Mat3) {{ \
	{n, n, n},              \
	{n, n, n},              \
	{n, n, n}               \
}}



#define \
MAT4_ID (Mat4) {{ \
	{1, 0, 0, 0},           \
	{0, 1, 0, 0},           \
	{0, 0, 1, 0},           \
	{0, 0, 0, 1}            \
}}

#define \
MAT4_ZERO (Mat4) {{ \
	{0, 0, 0, 0},             \
	{0, 0, 0, 0},             \
	{0, 0, 0, 0},             \
	{0, 0, 0, 0}              \
}}

#define \
MAT4_ONE (Mat4) {{ \
	{1, 1, 1, 1},           \
	{1, 1, 1, 1},           \
	{1, 1, 1, 1},           \
	{1, 1, 1, 1}            \
}}

#define \
MAT4_SET(n) (Mat4) {{ \
	{n, n, n, n},           \
	{n, n, n, n},           \
	{n, n, n, n},           \
	{n, n, n, n}            \
}}
