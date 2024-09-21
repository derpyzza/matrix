#include "../test.h"
#include "matrix.h"

#define EQ_CHECK( v1, v2 ) vec4_is_eq(v1, v2) 
#define NEQ_CHECK( v1, v2 ) vec4_is_neq(v1, v2) 
#define V_STRING( v ) vec4_string(v)

__impl(mat4_mult_vec4) {
	
	vec4_u v1 = vec4_new(1, 2, 3, 4),
				 v2 = vec4_new(1, 8, 3, 4);
	mat4_u m = mat4_id();
	m.yy = 4;

	ASSERT_EQ_T(vec4_mul_mat4(v1, m), v2);

	return PASS;
}


__suite(vec4) {
	__init("testing vec4");

	__test("Multiplying vec4s with mat4s", mat4_mult_vec4);

	return __results;
}
