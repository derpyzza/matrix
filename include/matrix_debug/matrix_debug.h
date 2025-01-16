#pragma once

#include <matrix/matrix_types.h>

/* @brief transforms a vec2 into a string version */
char* vec2_string( Vec2 v);
char* vec2_arr_string(float v[2]);

/* @brief transforms a vec3 into a string version */
char* vec3_string( Vec3 v);
char* vec3_arr_string(float v[3]);

/* @brief transforms a vec4 into a string version */
char* vec4_string( Vec4 v);
char* vec4_arr_string(float v[4]);

/* @brief transforms a mat3 into a string version */
char* mat3_string( Mat3 v);
char* mat3_arr_string(float v[9]);

/* @brief transforms a mat4 into a string version */
char* mat4_string( Mat4 v);
char* mat4_arr_string(float v[16]);
