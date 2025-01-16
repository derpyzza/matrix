#pragma once
#include <math.h>
#include <matrix/matrix.h>

#include "internal.h"

bool
vec2_is_eq( Vec2 v1, Vec2 v2 ) {
	return ( v1.x == v2.x && v1.y == v2.y );
}

bool
vec2_is_neq( Vec2 v1, Vec2 v2 ) {
	return ( v1.x != v2.x || v1.y != v2.y );
}

Vec2 
vec2_add(Vec2 v1, Vec2 v2) {
	return vec2_new(v1.x + v2.x, v1.y + v2.y);
}

Vec2 
vec2_sub ( Vec2 v1, Vec2 v2) {
	return vec2_new(v1.x - v2.x, v1.y - v2.y);
}

Vec2 
vec2_div ( Vec2 v1, Vec2 v2) {
	return vec2_new(v1.x / v2.x, v1.y / v2.y);
}

Vec2 
vec2_mul ( Vec2 v1, Vec2 v2) {
	return vec2_new(v1.x * v2.x, v1.y * v2.y);
}

Vec2
vec2_scale ( Vec3 vec1, float scalar) {
	return vec2_new(vec1.x * scalar, vec1.y * scalar);
}

Vec2 
vec2_neg( Vec3 v ) {
	return vec2_new(
		v.x ? v.x * -1 : v.x, 
		v.y ? v.y * -1 : v.y );
}

Vec2 
vec2_lerp( Vec2 v1, Vec2 v2, float t ) {
	Vec2 v;
	v.x = lerp(v1.x, v2.x, t);
	v.y = lerp(v1.y, v2.y, t);
	return v;
}

Vec2 
vec2_length_squared ( Vec2 v ) {
	return vec2_new(v.x * v.x, v.y * v.y);
}

float 
vec2_length ( Vec2 v ) {
	return sqrtf( v.x * v.x + v.y * v.y );
}

float 
vec2_dot (Vec2 v1, Vec2 v2) {
	return (
		v1.x * v2.x +
		v1.y * v2.y
	);
}

Vec2 
vec2_normalized (Vec2 v) {
	const float len = vec2_length(v);
	v.x /= len;
	v.y /= len;

	return v;
}
