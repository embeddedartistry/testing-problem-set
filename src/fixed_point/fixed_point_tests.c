#include <unity.h>
#include <stdbool.h>
#include "fixed_point.h"

#if 0
Do ZOMBIES here!
- Convert 0
- Convert 1
- Then start doing MORE complex
	- different exponents
	- negative numbers
- boundary conditions to think about
	- negative numbers, negative epxonents
#endif

/// Want to check some of these values for yourself?
/// Verify them with this page:
/// https://www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html

static void double_to_fixed16_test()
{
	fixed_point_t output_round = double_to_fixed_round(11.5);
	fixed_point_t output_truncate = double_to_fixed_truncate(11.5);
	TEST_ASSERT_EQUAL_INT(0x170, output_truncate);
	TEST_ASSERT_EQUAL_INT(output_round, output_truncate);

	output_round = double_to_fixed_round(128);
	output_truncate = double_to_fixed_truncate(128);
	TEST_ASSERT_EQUAL_INT(0x1000, output_truncate);
	TEST_ASSERT_EQUAL_INT(output_round, output_truncate);

#ifndef USE_UNSIGNED_FIXED_POINT
	output_round = double_to_fixed_round(-128);
	output_truncate = double_to_fixed_truncate(-128);
	TEST_ASSERT_EQUAL_INT((int16_t)0xf000, output_truncate);
	TEST_ASSERT_EQUAL_INT(output_round, output_truncate);

	output_round = double_to_fixed_round(-0.968750);
	output_truncate = double_to_fixed_truncate(-0.968750);
	TEST_ASSERT_EQUAL_INT((int16_t)0xffe1, output_truncate);
	TEST_ASSERT_EQUAL_INT(output_round, output_truncate);
#endif

	output_round = double_to_fixed_round(128.28);
	output_truncate = double_to_fixed_truncate(128.28);
	TEST_ASSERT_EQUAL_INT(0x1009, output_round);
	// Here, truncate loses precision vs round
	TEST_ASSERT_EQUAL_INT(0x1008, output_truncate);

#ifndef USE_UNSIGNED_FIXED_POINT
	output_round = double_to_fixed_round(-64.28);
	output_truncate = double_to_fixed_truncate(-64.28);
	TEST_ASSERT_EQUAL_INT((int16_t)0xf7f7, output_round);
	// Here, truncate loses precision vs round
	TEST_ASSERT_EQUAL_INT((int16_t)0xf7f8, output_truncate);
#endif
}

static void fixed16_to_double_test()
{
	double output = fixed_to_double(0x1000);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 128.0, output);

#ifndef USE_UNSIGNED_FIXED_POINT
	output = fixed_to_double(0xf000);
	TEST_ASSERT_FLOAT_WITHIN(0.01, -128.0, output);

	output = fixed_to_double(0xf7f7);
	TEST_ASSERT_FLOAT_WITHIN(0.01, -64.28125, output);

	// Check case presented in website comments
	output = fixed_to_double(0xffe1);
	TEST_ASSERT_FLOAT_WITHIN(0.0001, -0.968750, output);
#endif

	output = fixed_to_double(0x1009);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 128.28125, output);

	output = fixed_to_double(0x1008);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 128.25, output);

	output = fixed_to_double(0x1F);
	TEST_ASSERT_FLOAT_WITHIN(0.0001, 0.968750, output);

	// Confirm equivalency
	output = fixed16_to_double(0x1008, 5);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 128.25, output);

	// Check an alternate FP strategy - 10.6
	output = fixed16_to_double(0x1008, 6);
	TEST_ASSERT_FLOAT_WITHIN(0.01, 64.125, output);
}

#pragma mark - Public Functions -

int fixed_point_test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(fixed16_to_double_test);
	RUN_TEST(double_to_fixed16_test);
	return UNITY_END();
}
