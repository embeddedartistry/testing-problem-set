#include <unity.h>
#include <stdbool.h>
#include "fixed_point.h"

#if 0
These tests will benefit from a ZOMBIES approach:
- Does 0 convert?
- Does 1.0 convert?
- Then start doing more complex values:
	- larger integers
	- decimal values
	- varying the number of fractional bits (fixed16_to_double)
- Boundary conditions to think about:
	- negative numbers
	- small numbers, e.g. -0.5 < x < 0.5
	- loss of precision vs a floating point number
		- How do the round() and truncate() versions differ?

Sample values:
- 128.0 -> 0x1000
- -128.0 -> 0xf000
- -0.968750 -> 0xffe1

Want to check some of these values for yourself? Verify them with this page:
https://www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html

#endif

int fixed_point_test_suite(void);

static void double_to_fixed16_test()
{
	// TODO: test double -> fixed point conversion
}

static void fixed16_to_double_test()
{
	// TODO: test fixed -> double conversion
}

#pragma mark - Public Functions -

int fixed_point_test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(fixed16_to_double_test);
	RUN_TEST(double_to_fixed16_test);
	return UNITY_END();
}
