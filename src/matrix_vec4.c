#pragma once
#include <math.h>
#include <matrix/matrix.h>

#include "internal.h"

bool
vec4_is_eq( Vec4 v1, Vec4 v2 ) {
	return (
			v1.x == v2.x &&
			v1.y == v2.y &&
			v1.z == v2.z &&
			v1.w == v2.w 
	);
}

bool
vec4_is_neq( Vec4 v1, Vec4 v2 ) {
	return (
			v1.x != v2.x ||
			v1.y != v2.y ||
			v1.z != v2.z ||
			v1.w != v2.w
	);
}

Vec4 
vec4_add(Vec4 v1, Vec4 v2) {
	return vec4_new(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z,
			v1.w + v2.w);
}

Vec4 
vec4_sub(Vec4 v1, Vec4 v2) {
	return vec4_new(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z,
			v1.w - v2.w
			);
}

Vec4 
vec4_mul(Vec4 v1, Vec4 v2) {
	return vec4_new(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z,
			v1.w * v2.w
			);
}

Vec4 
vec4_div(Vec4 v1, Vec4 v2) {
	return vec4_new(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z,
			v1.w / v2.w
			);
}

Vec4 
vec4_scale(Vec4 v, float scalar) {
	return vec4_new(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar,
			v.w * scalar);
}


Vec4 
vec4_neg( Vec4 v ) {
	return vec4_new( 
		v.x ? v.x * -1 : v.x, 
		v.y ? v.y * -1 : v.y, 
		v.z ? v.z * -1 : v.z, 
		v.w ? v.w * -1 : v.w
	);
}

Vec4 
vec4_length_squared ( Vec4 v ) {
	return vec4_new(
		v.x * v.x,
		v.y * v.y,
		v.z * v.z,
		v.w * v.w
	);
}

float 
vec4_length( Vec4 v ) {
	return sqrtf( 
		v.x * v.x
	+ v.y * v.y
	+ v.z * v.z
	+ v.w * v.w
	);
}

Vec4 
vec4_normalized(Vec4 v) {
	const float len = vec4_length(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	v.w /= len;

	return v;
}

Vec4 
vec4_lerp( Vec4 v1, Vec4 v2, float t ) {
	Vec4 v;
	v.x = lerp(v1.x, v2.x, t);
	v.y = lerp(v1.y, v2.y, t);
	v.z = lerp(v1.z, v2.z, t);
	v.w = lerp(v1.w, v2.w, t);
	return v;
}

Vec4 
vec4_mul_mat4( Vec4 v, Mat4 m ) {
	Vec4 vec = VEC4_ONE;
	vec.x = (m.data[0][0] * v.x) + (m.data[0][1] * v.y) + (m.data[0][2] * v.z) + (m.data[0][3] * v.w);
	vec.y = (m.data[1][0] * v.x) + (m.data[1][1] * v.y) + (m.data[1][2] * v.z) + (m.data[1][3] * v.w);
	vec.z = (m.data[2][0] * v.x) + (m.data[2][1] * v.y) + (m.data[2][2] * v.z) + (m.data[2][3] * v.w);
	vec.w = (m.data[3][0] * v.x) + (m.data[3][1] * v.y) + (m.data[3][2] * v.z) + (m.data[3][3] * v.w);
	return vec;
}

