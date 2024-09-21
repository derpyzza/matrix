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
  union {
		struct {
    	float xx, xy, xz;
    	float yx, yy, yz;
    	float zx, zy, zz;
		};
		struct {
    	float a, b, c;
    	float d, e, f;
    	float g, h, i;
		};
  };
} mat3_u;

typedef union mat4_u {
  float data[16];
	union {
		struct {
			float xx, xy, xz, xw;
			float yx, yy, yz, yw;
			float zx, zy, zz, zw;
			float wx, wy, wz, ww;
		};
		struct {
			float a, b, c, d;
			float e, f, g, h;
			float i, j, k, l;
			float m, n, o, p;
		};
  };
} mat4_u;
