#include "../matrix.h"
#include <math.h>

vec4_u vec4_zero(void)
{
	return vec4_new(0,0,0,0);
}

vec4_u vec4_one(void) 
{
	return vec4_new(1,1,1,1);
}

vec4_u vec4_from_vec3(vec3_u v)
{
	return vec4_new(v.x, v.y, v.z, 1);
}

int vec4_is_eq( vec4_u v1, vec4_u v2 )
{
	return (
			v1.x == v2.x &&
			v1.y == v2.y &&
			v1.z == v2.z &&
			v1.w == v2.w 
	);
}

int vec4_is_neq( vec4_u v1, vec4_u v2 )
{
	return (
			v1.x != v2.x ||
			v1.y != v2.y ||
			v1.z != v2.z ||
			v1.w != v2.w
	);
}

vec4_u vec4_add(vec4_u v1, vec4_u v2)
{
	return vec4_new(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z,
			v1.w + v2.w);
}

vec4_u vec4_sub(vec4_u v1, vec4_u v2)
{
	return vec4_new(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z,
			v1.w - v2.w
			);
}

vec4_u vec4_mul(vec4_u v1, vec4_u v2)
{
	return vec4_new(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z,
			v1.w * v2.w
			);
}

vec4_u vec4_div(vec4_u v1, vec4_u v2)
{
	return vec4_new(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z,
			v1.w / v2.w
			);
}

vec4_u vec4_scale(vec4_u v, float scalar)
{
	return vec4_new(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar,
			v.w * scalar);
}


vec4_u vec4_neg( vec4_u v )
{
	return vec4_new( 
		v.x ? v.x * -1 : v.x, 
		v.y ? v.y * -1 : v.y, 
		v.z ? v.z * -1 : v.z, 
		v.w ? v.w * -1 : v.w
	);
}

vec4_u vec4_length_squared ( vec4_u v )
{
	return vec4_new(
		v.x * v.x,
		v.y * v.y,
		v.z * v.z,
		v.w * v.w
	);
}

float vec4_length( vec4_u v )
{
	return sqrtf( 
		v.x * v.x
	+ v.y * v.y
	+ v.z * v.z
	+ v.w * v.w
	);
}

vec4_u vec4_normalized(vec4_u v)
{
	const float len = vec4_length(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	v.w /= len;

	return v;
}

vec4_u vec4_lerp( vec4_u v1, vec4_u v2, float t )
{
	vec4_u v;
	v.x = lerp(v1.x, v2.x, t);
	v.y = lerp(v1.y, v2.y, t);
	v.z = lerp(v1.z, v2.z, t);
	v.w = lerp(v1.w, v2.w, t);
	return v;
}

vec4_u vec4_mul_mat4( vec4_u v, mat4_u m )
{
	vec4_u vec = vec4_one();

	vec.x = (m.xx * v.x) + (m.xy * v.y) + (m.xz * v.z) + (m.xw * v.w);
	vec.y = (m.yx * v.x) + (m.yy * v.y) + (m.yz * v.z) + (m.yw * v.w);
	vec.z = (m.zx * v.x) + (m.zy * v.y) + (m.zz * v.z) + (m.zw * v.w);
	vec.w = (m.wx * v.x) + (m.wy * v.y) + (m.wz * v.z) + (m.ww * v.w);
	return vec;
}



quat quat_id( void )
{
	return vec4_new( 0, 0, 0, 1);
}
