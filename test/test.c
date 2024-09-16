#include "test.h"

int
main(void) {

	int total = 0;
	int failed = 0;
	int passed = 0;

	matrix_test_func();
	test_results results;

	__check(vec2);
	__check(vec3);
	__check(vec4);
	__check(mat3);
	__check(mat4);

	printf(
			"===TESTING COMPLETE===\n"
			"Total tests: %i, Passed: %i, Failed: %i\n", total, passed, failed);

	return 0;
}
