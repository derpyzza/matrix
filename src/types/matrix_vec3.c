#include "../matrix.h"
#include <math.h>

vec3_u vec3_zero(void)
{
	return vec3_new(0,0,0);
}

vec3_u vec3_one(void)
{
	return vec3_new(1, 1, 1);
}

vec3_u vec3_up(void)
{ 
	return vec3_new(0, -1, 0);
}

vec3_u vec3_down(void)
{
	return vec3_new(0, 1, 0);
}

vec3_u vec3_left(void)
{
	return vec3_new(-1, 0, 0);
}

vec3_u vec3_right(void)
{
	return vec3_new(1, 0, 0);
}

vec3_u vec3_forward(void)
{
	return vec3_new(0, 0, 1);
}

vec3_u vec3_backward(void)
{
	return vec3_new(0, 0, -1);
}

int vec3_is_eq( vec3_u v1, vec3_u v2 )
{ 
	return ( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z );
}

int vec3_is_neq( vec3_u v1, vec3_u v2 )
{ 
	return ( v1.x != v2.x || v1.y != v2.y || v1.z != v2.z );
}

vec3_u vec3_add(vec3_u v1, vec3_u v2)
{
	return vec3_new(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

vec3_u vec3_sub(vec3_u v1, vec3_u v2)
{
	return vec3_new(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

vec3_u vec3_div(vec3_u v1, vec3_u v2)
{
	return vec3_new(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

vec3_u vec3_mul(vec3_u v1, vec3_u v2)
{
	return vec3_new(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

vec3_u vec3_scale(vec3_u vec1, float scalar)
{
	return vec3_new(vec1.x * scalar, vec1.y * scalar, vec1.z * scalar);
}

vec3_u vec3_neg( vec3_u v )
{
	return vec3_new( 
		v.x ? v.x * -1 : v.x, 
		v.y ? v.y * -1 : v.y, 
		v.z ? v.z * -1 : v.z
	);
}

vec3_u vec3_lerp( vec3_u v1, vec3_u v2, float t )
{
	vec3_u v;
	v.x = lerp(v1.x, v2.x, t);
	v.y = lerp(v1.y, v2.y, t);
	v.z = lerp(v1.z, v2.z, t);
	return v;
}

vec3_u vec3_length_squared ( vec3_u v )
{
	return vec3_new( v.x * v.x, v.y * v.y, v.z * v.z);
}

float vec3_length( vec3_u v )
{
	return sqrtf( v.x * v.x + v.y * v.y + v.z * v.z );
}

vec3_u vec3_normalized(vec3_u v)
{
	const float len = vec3_length(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return v;
}

float vec3_dot(vec3_u v1, vec3_u v2)
{
	float r = 0;
	for (int i = 0; i < 3; i++) {
		r += v1.data[i] * v2.data[1];
	}
	return r;
}

vec3_u vec3_cross(vec3_u v1, vec3_u v2)
{
	return vec3_new( 
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	);
}
