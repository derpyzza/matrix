#include "../matrix.h"
#include <math.h>
#include <string.h>

mat3_u mat3_zero(void)
{
  return mat3_new(
		(float[9]){
			0, 0, 0,
			0, 0, 0,
			0, 0, 0,
		}
  );
}

mat3_u mat3_id(void)
{
	return mat3_new(
		(float[9]){
			1, 0, 0,
			0, 1, 0,
			0, 0, 1
		}
	);
}

mat4_u 	mat4_zero(void)
{
  return mat4_new(
		(float[16]){
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0
		}
  );
}

// mat4_u 	mat4_one(void){
//   return mat4_new(
//     1, 1, 1, 1,
//     1, 1, 1, 1,
//     1, 1, 1, 1,
//     1, 1, 1, 1
//   );
// }

mat4_u 	mat4_id(void)
{
	mat4_u m;
	memset(&m, 0, sizeof(m));
	m.x.x = 1;
	m.y.y = 1;
	m.z.z = 1;
	m.w.w = 1;
	return m;
}

mat4_u mat4_from_vec3s ( vec3_u x, vec3_u y, vec3_u z )
{
	return mat4_new(
		(float[16]){
			x.x, x.y, x.z, 0,
			y.x, y.y, y.z, 0,
			z.x, z.y, z.z, 0,
			0, 0, 0, 1
		}
	);
}

mat4_u 	mat4_scale(mat4_u matrix, vec3_u scale)
{
	mat4_u m = matrix;
	m.x.x *= scale.x;
	m.y.y *= scale.y;
	m.z.z *= scale.z;
	return m;
}

mat4_u mat4_mul(mat4_u m1, mat4_u m2)
{
	mat4_u m = mat4_id();
	
	const float *m1_ptr = m1.data;
	const float *m2_ptr = m2.data;
	float *dst_ptr = m.data;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
				*dst_ptr = m1_ptr[0] * m2_ptr[0 + j] + m1_ptr[1] * m2_ptr[4 + j] +
									 m1_ptr[2] * m2_ptr[8 + j] + m1_ptr[3] * m2_ptr[12 + j];
				dst_ptr++;
		}
		m1_ptr += 4;
	}
	return m;

}

mat4_u mat4_translate(mat4_u m, vec3_u v)
{
	m.w.x += v.x;
	m.w.y += v.y;
	m.w.z += v.z;
	return m;
}

// mat4_u mat4_rot( mat4_u m, float rad, vec3_u axis) {
// 	return mat4_id();
// }

mat4_u mat4_rotx( mat4_u m, float rad )
{
	mat4_u rot = mat4_new(
		(float[16])
		{
		1, 0, 0, 0,
		0, cos(rad), sin(rad), 0,
		0, -sin(rad), cos(rad), 0,
		0, 0, 0, 1
		}
	);
	return mat4_mul(m, rot);
}

mat4_u mat4_roty( mat4_u m, float rad )
{
		mat4_u rot = mat4_new(
		(float[16])
		{
		cos(rad), sin(rad), 0, 0,
		0, 1, 0, 0,
		-sin(rad), cos(rad), 0, 0,
		0, 0, 0, 1
		}
	);
	return mat4_mul(m, rot);
}

mat4_u mat4_rotz( mat4_u m, float rad )
{
		mat4_u rot = mat4_new(
		(float[16])
		{
		cos(rad), sin(rad), 0, 0,
		-sin(rad), cos(rad), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		}
	);
	return mat4_mul(m, rot);
}

mat4_u persp(float fov, float near, float far, float ratio)
{
	return mat4_id();
}

mat4_u ortho(float left, float right, float bottom, float top, float near, float far)
{
	return mat4_id();
}

mat4_u look_at(vec3_u position, vec3_u target, vec3_u up)
{
	return mat4_id();
}
