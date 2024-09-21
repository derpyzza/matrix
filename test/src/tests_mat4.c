#include "../test.h"

#define EQ_CHECK( v1, v2 ) mat4_is_eq(v1, v2) 
#define NEQ_CHECK( v1, v2 ) mat4_is_neq(v1, v2) 
#define V_STRING( v ) vec4_string(v)

__impl(mat4_scale) {
	mat4_u m1 = mat4_one(), m2 = mat4_new(
			(float[16]) {
			4, 3, 2, 0,
			2, 4, 3, 0,
			3, 2, 4, 0,
			0, 0, 0, 0,
			}
			);

	printf("scaled matrix 1:\n%s\n", mat4_string(mat4_scale(m1, (vec3_u){2, 3, 4})));
	printf("scaled matrix 2:\n%s\n", mat4_string(mat4_scale(m2, (vec3_u){2, 3, 4})));
	return PASS;
}

__suite(mat4) {
	__init("testing mat4");

	__test("Testing matrix scaling", mat4_scale);

	return __results;
}
