#pragma once
#include <stdio.h>
#include <matrix.h>
#include <matrix_debug/matrix_debug.h>

#define PASS 1
#define FAIL 0

#define ASSERT_TRUE(expr) { \
	if (expr) {} \
	else {\
		printf("[FAIL] {" #expr "} returned false at (%s:%i)\n", __FILE__, __LINE__); \
		return FAIL; \
	} \
}

#define ASSERT_EQ_T(v1, v2) { \
	if ( EQ_CHECK(v1, v2) ) {} \
	else {\
		printf( \
				"[FAIL] unequal values at (%s:%i)\n" \
				"Return value: %s\nExpected Value: %s\n", \
				__FILE__, __LINE__, \
				V_STRING(v1), V_STRING(v2)); \
		return FAIL; \
	} \
}

#define ASSERT_NEQ(v1, v2) { \
	if ( NEQ_CHECK(v1, v2) ) {} \
	else {\
		printf( \
				"[FAIL] equal values at (%s:%i)\n" \
				"Return value: %s", \
				__FILE__, __LINE__, \
				V_STRING(v1)); \
		return FAIL; \
	} \
}

typedef struct test_results {
	int passed, failed;
} test_results;

#define __suite(NAME) test_results suite_ ##NAME (void)
#define __impl(NAME) int test_ ##NAME (void)
#define __init(msg) int passed = 0, failed = 0; printf(msg"\n")
#define __test(MSG, NAME) {		\
	if (test_ ##NAME ()) {			\
		printf("> "MSG" ... ok\n");		\
		passed++;									\
	}														\
	else { 											\
		failed++; 								\
	}														\
	}
#define __check(NAME) { results = suite_ ##NAME ();\
	passed += results.passed,\
	failed += results.failed,\
	total += (results.passed + results.failed); } 
#define __results (test_results){passed, failed}

__suite(vec2);
__suite(vec3);
__suite(vec4);
__suite(mat3);
__suite(mat4);
