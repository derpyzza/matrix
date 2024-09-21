#include "../test.h"
#include <matrix_debug/matrix_debug.h>
#include <matrix.h>

#define EQ_CHECK(v1, v2) vec2_is_eq(v1, v2)
#define NEQ_CHECK( v1, v2 ) vec2_is_neq(v1, v2) 
#define V_STRING( v ) vec2_string(v)

__impl(is_eq) {
	vec2_u v1, v2;
	v1 = v2 = vec2_zero();

	ASSERT_EQ_T(v1, v2);

	return PASS;
}

// __impl(add) {
// 	vec2_u v1 = vec2_new(3, 6), v2 = vec2_new(42.535, 264);
//
// 	if (vec2_is_eq(v1, v2) ) {}
// 	else {
//
// 	}
//
// 	ASSERT_EQ_T( vec2, vec2_add(v1, v2), vec2_new(45.535, 264));
// 	return PASS;
// }

__suite(vec2) {

	__init("testing vec2");

	__test("equality check", is_eq);
	// __test("add check", add);

	return __results;
}
