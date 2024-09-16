#pragma once
#include <stdio.h>
#include <matrix.h>
#include <matrix_debug/matrix_debug.h>

#define PASS 1
#define FAIL 0

typedef int (*test_func)(void);

#define ASSERT_TRUE(expr) { \
	if (expr) {} \
	else {\
		printf("[FAIL] {" #expr "} returned false at (%s:%i)\n", __FILE__, __LINE__); \
		return FAIL; \
	} \
}

#define ASSERT_TRUE_MSG(expr, MSG) { \
	if (expr) {} \
	else {\
		printf("[FAIL] {" #expr "} returned false at (%s:%i) with Msg: " MSG "\n", __FILE__, __LINE__); \
		return FAIL; \
	} \
}

#define ASSERT_FALSE(expr) { \
	if (expr) {\
		printf("[FAIL] {" #expr "} returned true at (%s:%i)\n", __FILE__, __LINE__); \
		return FAIL; \
	} \
}

#define ASSERT_FALSE_MSG(expr, MSG) { \
	if (expr) {\
		printf("[FAIL] {" #expr "} returned true at (%s:%i) with Msg: " MSG "\n", __FILE__, __LINE__); \
		return FAIL; \
	} \
}

typedef struct test_results {
	int passed, failed;
} test_results;

#define __decl(NAME) test_results suite_ ##NAME (void)
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

__decl(vec2);
__decl(vec3);
__decl(vec4);
__decl(mat3);
__decl(mat4);
