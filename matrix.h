#pragma once

#ifdef MATRIX_DEBUG_FUNCTIONS
	#include "matrix_debug.h"
#endif

#include "matrix_types.h"

#include "matrix_vec2.h"
#include "matrix_vec3.h"
#include "matrix_vec4.h"
#include "matrix_mat2.h"
#include "matrix_mat3.h"
#include "matrix_mat4.h"

//
// Vector constants
//
/* === 3x3 MATRIX FUNCTIONS === */
Mat4 mat4_float(float);
Mat4 mat4_id(void);
Mat4 mat4_scale(Mat4 matrix, Vec3 scale);
Mat4 mat4_scale_matrix(Mat4 matrix, Vec3 scale);
Mat4 mat4_mul(Mat4 m1, Mat4 m2);
Mat4 mat4_translate(Mat4 m, Vec3 v);
Mat4 mat4_rot(Mat4 m, float rad, Vec3 axis);
Mat4 mat4_rotx(Mat4 m, float rad);
Mat4 mat4_roty(Mat4 m, float rad);
Mat4 mat4_rotz(Mat4 m, float rad);
Mat4 persp(float fov, float near, float far, float ratio);
Mat4 ortho(float left, float right, float bottom, float top, float near, float far);
Mat4 look_at(Vec3 pos, Vec3 target, Vec3 up);
quat quat_id(void);
