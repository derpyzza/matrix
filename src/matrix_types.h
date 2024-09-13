#pragma once

typedef union vec2_u {
  float data[2];
  struct {
    union { float x, u; };
    union { float y, v; };
  };
} vec2_u;

typedef union vec3_u {
  float data[3];
  struct {
    union {
      float x, r;
    };
    union {
      float y, g;
    };
    union {
      float z, b;
    };
  };
} vec3_u;

typedef union vec4_u {
  float data[4];
  struct {
    union {
      float x, r;
    };
    union {
      float y, g;
    };
    union {
      float z, b;
    };
    union {
      float w, a, i;
    };
  };
} vec4_u;

typedef vec4_u quat;

typedef union mat3_u {
  float data[9];
  struct {
    vec3_u x, y, z;
  };
} mat3_u;

typedef union mat4_u {
  float data[16];
  struct {
    vec4_u x, y, z, w;
  };
} mat4_u;
