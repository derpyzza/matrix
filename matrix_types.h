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
static inline float clamp ( float val, float top, float bottom ) {
	return max(bottom, min(val, top));
}

static inline float lerp ( float x, float y, float t ) {
	return x + (( y - x ) * t);
}

typedef struct Vec2 {
  union { float x, u; };
  union { float y, v; };
} Vec2;

#define VEC2_ZERO   (Vec2) {  0,  0 }
#define VEC2_ONE    (Vec2) {  1,  1 }
#define VEC2_LEFT   (Vec2) { -1,  0 }
#define VEC2_RIGHT  (Vec2) {  1,  0 }
#define VEC2_UP     (Vec2) {  0, -1 }
#define VEC2_DOWN   (Vec2) {  0,  1 }
#define VEC2_SET(x) (Vec2) {  x,  x }

typedef struct Vec3 {
  union { float x, r, u; };
  union { float y, g, v; };
  union { float z, b, t; };
} Vec3;

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

typedef struct Vec4 {
  union { float x, r; };
  union { float y, g; };
  union { float z, b; };
  union { float w, a, i; };
} Vec4;

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

typedef Vec4 quat;

typedef struct Mat2 {
	float data[2][2];
} Mat2;

typedef struct Mat3 {
  float data[3][3];
} Mat3;

typedef struct Mat4 {
  float data[4][4];
} Mat4;

static inline
Mat2 mat2_new ( float data[4] ) {
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
