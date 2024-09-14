#ifdef MATRIX_DEBUG_FUNCTIONS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "matrix_debug.h"

// 1024 should be plenty
#define matrix_S_BUF_SIZE 1024

char *vec2_string(vec2_u v)
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s, "vec2(x: %4.2f, y: %4.2f)", v.x, v.y);
  return s;
}

char* vec2_arr_string(float v[2])
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s, "vec2(x: %4.2f, y: %4.2f)", v[0], v[1]);
  return s;
}

char *vec3_string(vec3_u v)
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s, "vec3(x: %4.2f, y: %4.2f, z: %4.2f)", v.x, v.y, v.z);
  return s;
}

char* vec3_arr_string(float v[3])
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s, "vec3(x: %4.2f, y: %4.2f, z: %4.2f)", v[0], v[1], v[2]);
  return s;
}

char *vec4_string(vec4_u v)
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s, "vec4(x: %4.2f, y: %4.2f, z: %4.2f, w: %4.2f)", v.x, v.y, v.z,
          v.w);
  return s;
}

char* vec4_arr_string(float v[4])
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s, "vec4(x: %4.2f, y: %4.2f, z: %4.2f, w: %4.2f)", v[0], v[1], v[2],
          v[3]);
  return s;
}

char *mat3_string(mat3_u v)
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s,
          "mat3(\n"
          "  xx: %4.2f, xy: %4.2f, xz: %4.2f,\n"
          "  yx: %4.2f, yy: %4.2f, yz: %4.2f,\n"
          "  zx: %4.2f, zy: %4.2f, zz: %4.2f)\n",
          v.x.x, v.x.y, v.x.z, v.y.x, v.y.y, v.y.z, v.z.x, v.z.y, v.z.z);
  return s;
}

char* mat3_arr_string(float v[9])
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s,
          "mat3(\n"
          "  xx: %4.2f, xy: %4.2f, xz: %4.2f,\n"
          "  yx: %4.2f, yy: %4.2f, yz: %4.2f,\n"
          "  zx: %4.2f, zy: %4.2f, zz: %4.2f)\n",
          v[0], v[1], v[2], 
					v[3], v[4], v[5], 
					v[6], v[7], v[8]);
  return s;
}

char *mat4_string(mat4_u v) 
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s,
          "mat4(\n"
          "  xx: %4.2f, xy: %4.2f, xz: %4.2f, xw: %4.2f\n"
          "  yx: %4.2f, yy: %4.2f, yz: %4.2f, yw: %4.2f\n"
          "  zx: %04.2f, zy: %4.2f, zz: %4.2f, zw: %4.2f\n"
          "  wx: %4.2f, wy: %4.2f, wz: %4.2f, ww: %4.2f)",
          v.x.x, v.x.y, v.x.z, v.x.w, v.y.x, v.y.y, v.y.z, v.y.w, v.z.x, v.z.y,
          v.z.z, v.z.w, v.w.x, v.w.y, v.w.z, v.w.w);
  return s;
}

char *mat4_arr_string(float v[16])
{
  char *s = malloc(sizeof(char) * matrix_S_BUF_SIZE);
  memset(s, 0, sizeof(char) * matrix_S_BUF_SIZE);
  sprintf(s,
          "mat4(\n"
          "  xx: %4.2f, xy: %4.2f, xz: %4.2f, xw: %4.2f\n"
          "  yx: %4.2f, yy: %4.2f, yz: %4.2f, yw: %4.2f\n"
          "  zx: %04.2f, zy: %4.2f, zz: %4.2f, zw: %4.2f\n"
          "  wx: %4.2f, wy: %4.2f, wz: %4.2f, ww: %4.2f)",
          v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10],
          v[11], v[12], v[13], v[14], v[15]);
  return s;
}
#endif
