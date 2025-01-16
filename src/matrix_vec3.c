#pragma once
#include <math.h>
#include <matrix/matrix.h>

#include "internal.h"

int 
vec3_is_eq ( Vec3 v1, Vec3 v2 ) { 
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z );
}

int 
vec3_is_neq ( Vec3 v1, Vec3 v2 ) { 
	return ( v1.x != v2.x || v1.y != v2.y || v1.z != v2.z );
}

Vec3
vec3_add (Vec3 v1, Vec3 v2) {
	return vec3_new(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3
vec3_sub (Vec3 v1, Vec3 v2) {
	return vec3_new(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3
vec3_div (Vec3 v1, Vec3 v2) {
	return vec3_new(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

Vec3
vec3_mul (Vec3 v1, Vec3 v2) {
	return vec3_new(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

Vec3
vec3_scale (Vec3 vec1, float scalar) {
	return vec3_new(vec1.x * scalar, vec1.y * scalar, vec1.z * scalar);
}

Vec3
vec3_neg ( Vec3 v ) {
	return vec3_new( 
		v.x ? v.x * -1 : v.x, 
		v.y ? v.y * -1 : v.y, 
		v.z ? v.z * -1 : v.z
	);
}

Vec3
vec3_lerp ( Vec3 v1, Vec3 v2, float t ) {
	Vec3 v;
	v.x = lerp(v1.x, v2.x, t);
	v.y = lerp(v1.y, v2.y, t);
	v.z = lerp(v1.z, v2.z, t);
	return v;
}

Vec3
vec3_length_squared ( Vec3 v ) {
	return vec3_new( v.x * v.x, v.y * v.y, v.z * v.z);
}

float 
vec3_length ( Vec3 v ) {
	return sqrtf( v.x * v.x + v.y * v.y + v.z * v.z );
}

Vec3 
vec3_normalized (Vec3 v) {
	const float len = vec3_length(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return v;
}

float 
vec3_dot(Vec3 v1, Vec3 v2) {
	return (
		v1.x * v2.x +
		v1.y * v2.y + 
		v1.z * v2.z
	);
}

Vec3 
vec3_cross(Vec3 v1, Vec3 v2) {
	return vec3_new( 
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	);
}
