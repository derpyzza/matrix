#define MATRIX_DEBUG_FUNCTIONS
#ifdef MATRIX_DEBUG_FUNCTIONS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <matrix_debug/matrix_debug.h>

// 1024 should be plenty
#define MTX_S_BUF_SIZE 1024

char* 
vec2_string ( Vec2 v ) {
  char *s = calloc(sizeof(char), MTX_S_BUF_SIZE);
  sprintf(s, "vec2(x: %4.2f, y: %4.2f)", v.x, v.y);
  return s;
}

char* 
vec3_string( Vec3 v ) {
  char *s = calloc(sizeof(char), MTX_S_BUF_SIZE);
  sprintf(s, "vec3(x: %4.2f, y: %4.2f, z: %4.2f)", v.x, v.y, v.z);
  return s;
}

char*
vec4_string( Vec4 v ) {
  char *s = calloc(sizeof(char), MTX_S_BUF_SIZE);
  sprintf(s, 
          "vec4(x: %4.2f, y: %4.2f, z: %4.2f, w: %4.2f)",
          v.x, v.y, v.z, v.w );
  return s;
}

// we don't talk about this
#define d m.data 

char* 
mat2_string( Mat2 m ) {
  char *s = calloc(sizeof(char), MTX_S_BUF_SIZE);
  sprintf(s,
          "mat2(\n"
          "  ax: %4.2f, bx: %4.2f\n"
          "  ay: %4.2f, by: %4.2f\n",
          d[0][0], d[0][1],
          d[1][0], d[1][1] );
  return s;
}

char* 
mat3_string( Mat3 m ) {
  char *s = calloc(sizeof(char), MTX_S_BUF_SIZE);
  sprintf(s,
          "mat3(\n"
          "  ax: %4.2f, bx: %4.2f, cx: %4.2f,\n"
          "  ay: %4.2f, by: %4.2f, cy: %4.2f,\n"
          "  az: %4.2f, bz: %4.2f, cz: %4.2f)\n",
          d[0][0], d[0][1], d[0][2], 
          d[1][0], d[1][1], d[1][2], 
          d[2][0], d[2][1], d[2][2] );
  return s;
}

char*
mat4_string(Mat4 m) {
  char *s = calloc(sizeof(char), MTX_S_BUF_SIZE);
  sprintf(s,
          "mat4(\n"
          "  ax: %4.2f, ay: %4.2f, az: %4.2f, aw: %4.2f\n"
          "  bx: %4.2f, by: %4.2f, bz: %4.2f, bw: %4.2f\n"
          "  cx: %4.2f, cy: %4.2f, cz: %4.2f, cw: %4.2f\n"
          "  dx: %4.2f, dy: %4.2f, dz: %4.2f, dw: %4.2f)",
          d[0][0], d[0][1], d[0][2], d[0][3], 
          d[1][0], d[1][1], d[1][2], d[1][3], 
          d[2][0], d[2][1], d[2][2], d[2][3], 
          d[3][0], d[3][1], d[3][2], d[3][3] );
  return s;
}
#undef d
#endif
