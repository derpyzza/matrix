#include "../test.h"

#define EQ_CHECK( v1, v2 ) mat3_is_eq(v1, v2) 
#define NEQ_CHECK( v1, v2 ) mat3_is_neq(v1, v2) 
#define V_STRING( v ) mat3_string(v)

__suite(mat3) {
	__init("testing mat3");

	return __results;
}
