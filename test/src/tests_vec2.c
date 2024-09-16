#include "../test.h"
#include <matrix.h>

__impl(is_eq) {
	vec2_u v1, v2;
	v1 = v2 = vec2_zero();

	ASSERT_TRUE(vec2_is_eq(v1, v2));
	ASSERT_FALSE(vec2_is_neq(v1, v2));
	v1.x = 1;
	ASSERT_FALSE(vec2_is_eq(v1, v2));
	v2.x++;
	ASSERT_TRUE(vec2_is_eq(v1, v2));
	
	v1.x = .4 + .5;
	v2.x = .3 + .6;
	ASSERT_TRUE(vec2_is_eq(v1, v2));

	return PASS;
}

__impl(add) {
	vec2_u v1 = vec2_new(3, 6), v2 = vec2_new(42.535, 264);

	ASSERT_TRUE(
			vec2_is_eq(
				vec2_add(v1, v2),
				vec2_new(43.535, 264)
				));
	return PASS;
}

__suite(vec2) {

	__init("testing vec2");

	__test("equality check", is_eq);
	__test("add check", add);

	return __results;
}
