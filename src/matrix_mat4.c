#pragma once
#include <math.h>
#include <string.h>

#include <matrix/matrix.h>

Mat4
mat4_from_vec3s ( Vec3 x, Vec3 y, Vec3 z ) {
	return mat4_new(
		(float[16]){
			x.x, x.y, x.z, 0,
			y.x, y.y, y.z, 0,
			z.x, z.y, z.z, 0,
			0, 0, 0, 1
		}
	);
}

Mat4 
mat4_scale_matrix (Mat4 m, Vec3 scale) {
	m.data[0][0]  = scale.x;
	m.data[1][1]  = scale.y;
	m.data[2][2]  = scale.z;
	return m;
}

Mat4 
mat4_scale(Mat4 matrix, Vec3 scale) {
	Mat4 m = matrix;
	for (int i = 0; i < 3; i++) {
		int index = (i * 3) + ( i * 1 );
		m.data[index] *= scale.x;
		m.data[index+1] *= scale.y;
		m.data[index+2] *= scale.z;
	}
	return m;
}

Mat4 
mat4_mul(Mat4 m1, Mat4 m2) {
	Mat4 m = MAT4_ID;
	
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

Mat4 
mat4_translate(Mat4 m, Vec3 v) {
	m.data[3][0] += v.x;
	m.data[3][1] += v.y;
	m.data[3][2] += v.z;
	return m;
}

// Mat4 mat4_rot( Mat4 m, float rad, vec3_u axis) {
// 	return mat4_id();
// }

Mat4 
mat4_rotx( Mat4 m, float rad ) {
	Mat4 rot = mat4_new(
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

Mat4 
mat4_roty( Mat4 m, float rad ) {
		Mat4 rot = mat4_new(
		(float[16])
		{
		cos(rad), 0, sin(rad), 0,
		0, 				1, 				0, 0,
		-sin(rad),0, cos(rad), 0,
		0, 				0, 				0, 1
		}
	);
	return mat4_mul(m, rot);
}

Mat4 
mat4_rotz( Mat4 m, float rad ) {
		Mat4 rot = mat4_new(
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

Mat4 
persp(float fov_rad, float near, float far, float ratio) {
	Mat4 out;
	memset(out.data, 0, sizeof(float) * 16);
	return out;
}

Mat4 
ortho(float left, float right, float bottom, float top, float near, float far) {
	return MAT4_ID;
}

Mat4 
look_at(Vec3 position, Vec3 target, Vec3 up) {
	return MAT4_ID;
}
