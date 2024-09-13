#ifdef MATRIX_DEBUG_FUNCTIONS

#include "matrix_types.h"

/* @brief transforms a vec2 into a string version */
char* vec2_string( vec2_u v);
char* vec2_arr_string(float v[2]);

/* @brief transforms a vec3 into a string version */
char* vec3_string( vec3_u v);
char* vec3_arr_string(float v[3]);

/* @brief transforms a vec4 into a string version */
char* vec4_string( vec4_u v);
char* vec4_arr_string(float v[4]);

/* @brief transforms a mat3 into a string version */
char* mat3_string( mat3_u v);
char* mat3_arr_string(float v[9]);

/* @brief transforms a mat4 into a string version */
char* mat4_string( mat4_u v);
char* mat4_arr_string(float v[16]);

#endif
