#include "../matrix.h"
#include <math.h>
#include <string.h>

mat3_u mat3_new( float data[9] )
{
  mat3_u m = (mat3_u) {{
    data[0],  data[1], data[2],
    data[3],  data[4], data[5],
    data[6],  data[6], data[8]
  }};

  return m;
}
mat3_u mat3_zero(void) {
  return (mat3_u) {{
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
  }};
}
// Returns the identity matrix
mat3_u mat3_id(void)
{
	return (mat3_u) {{
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
	}};
}

mat4_u 	mat4_new( float data[16] )
{
   return (mat4_u) {{
		 data[ 0],  data[ 1], data[ 2], data[ 3],
		 data[ 4],  data[ 5], data[ 6], data[ 7],
		 data[ 8],  data[ 9], data[10], data[11],
		 data[12],  data[13], data[14], data[15]
	 }};
}

mat4_u 	mat4_zero(void){
  return (mat4_u) {{
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0
  }};
}

// mat4_u 	mat4_one(void){
//   return (mat4_u) {{
//     1, 1, 1, 1,
//     1, 1, 1, 1,
//     1, 1, 1, 1,
//     1, 1, 1, 1
//   }};
// }

mat4_u 	mat4_id(void) {
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
	return (mat4_u) {
		x.x, x.y, x.z, 0,
		y.x, y.y, y.z, 0,
		z.x, z.y, z.z, 0,
		0, 0, 0, 1
	};
}

mat4_u 	mat4_scale(mat4_u matrix, vec3_u scale) {
	mat4_u m = matrix;
	m.x.x *= scale.x;
	m.y.y *= scale.y;
	m.z.z *= scale.z;
	return m;
}

mat4_u mat4_mul(mat4_u m1, mat4_u m2) {
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

mat4_u mat4_translate(mat4_u m, vec3_u v) {
	m.w.x += v.x;
	m.w.y += v.y;
	m.w.z += v.z;
	return m;
}

// mat4_u mat4_rot( mat4_u m, float rad, vec3_u axis) {
// 	return mat4_id();
// }

mat4_u mat4_rotx( mat4_u m, float rad ) {
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

mat4_u mat4_roty( mat4_u m, float rad ) {
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
mat4_u mat4_rotz( mat4_u m, float rad ) {
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

mat4_u 	persp(float fov, float near, float far, float ratio) {
	float half_tan_fov = tanf(fov * 0.5f);
	mat4_u m;
	memset(m.data, 0, sizeof(float) * 16);
	m.data[0] = 1.0f / (ratio * half_tan_fov);
	m.data[5] = 1.0f / half_tan_fov;
	m.data[10] = -((far + near) / (far - near));
	m.data[11] = -1.0f;
	m.data[14] = -((2.0f * far * near) / (far - near));
	return m;
}

mat4_u ortho(float left, float right, float bottom, float top, float near, float far)
{
    mat4_u out = mat4_id();

    float lr = 1.0f / (left - right);
    float bt = 1.0f / (bottom - top);
    float nf = 1.0f / (near - far);

    out.data[0] = -2.0f * lr;
    out.data[5] = -2.0f * bt;
    out.data[10] = 2.0f * nf;

    out.data[12] = (left + right) * lr;
    out.data[13] = (top + bottom) * bt;
    out.data[14] = (far + near) * nf;
    return out;
}

mat4_u look_at(vec3_u position, vec3_u target, vec3_u up) {
    mat4_u out;

    vec3_u z_axis = vec3_normalize(vec3_sub(target, position));
    vec3_u x_axis = vec3_normalize(vec3_cross(z_axis, up));
    vec3_u y_axis = vec3_cross(x_axis, z_axis);

    out.data[0] = x_axis.x;
    out.data[1] = y_axis.x;
    out.data[2] = -z_axis.x;
    out.data[3] = 0;
    out.data[4] = x_axis.y;
    out.data[5] = y_axis.y;
    out.data[6] = -z_axis.y;
    out.data[7] = 0;
    out.data[8] = x_axis.z;
    out.data[9] = y_axis.z;
    out.data[10] = -z_axis.z;
    out.data[11] = 0;
    out.data[12] = -vec3_dot(x_axis, position);
    out.data[13] = -vec3_dot(y_axis, position);
    out.data[14] = vec3_dot(z_axis, position);
    out.data[15] = 1.0f;

    return out;
}
