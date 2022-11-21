/*
 * Copyright © 2022 Embedded Artistry LLC.
 * See LICENSE file for licensing information.
 */

#include <unity.h>
#include <stdbool.h>

int test_suite(void);

static void test_case(void)
{
	TEST_ASSERT(false);
	// Full Assert macro reference: https://api.cmocka.org/group__cmocka__asserts.html
	// TEST_ASSERT_TRUE();
	// TEST_ASSERT_FALSE();
	// TEST_ASSERT();
	// TEST_FAIL();
	// TEST_FAIL_MESSAGE();
	// TEST_ASSERT_EQUAL_INT();
	// TEST_ASSERT_EQUAL_UINT();
	// TEST_ASSERT_INT_WITHIN(delta, expected, actual)
	// TEST_ASSERT_GREATER_THAN(threshold, actual)
	// TEST_ASSERT_LESS_THAN(threshold, actual)
	// TEST_ASSERT_BITS(mask, expected, actual)
	// TEST_ASSERT_EQUAL_STRING(expected, actual)
	// TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual)
	// TEST_ASSERT_DOUBLE_WITHIN(delta, expected, actual)
	// TEST_ASSERT_EQUAL_FLOAT(expected, actual)
	// TEST_ASSERT_EQUAL_STRING_LEN(expected, actual, len)
	// TEST_ASSERT_NULL(pointer) (or NOT_NULL)
	// TEST_ASSERT_EQUAL_MEMORY(expected, actual, len)
	/* _MESSAGE
	* You can append \_MESSAGE to any of the macros to make them take an additional
	* argument. This argument is a string that will be printed at the end of the
	* failure strings. This is useful for specifying more information about the problem.
	*/
}

#pragma mark - Public Functions -

int test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_case);
	return UNITY_END();
}
