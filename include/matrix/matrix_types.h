#pragma once

typedef struct Vec2 {
  float x, y;
} Vec2;

typedef struct Vec3 {
  float x, y, z;
} Vec3;

typedef struct Vec4 {
  float x, y, z, w;
} Vec4;

typedef Vec4 Quat;

typedef struct Mat2 {
	float data[2][2];
} Mat2;

typedef struct Mat3 {
  float data[3][3];
} Mat3;

typedef struct Mat4 {
  float data[4][4];
} Mat4;
