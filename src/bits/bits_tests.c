#include <unity.h>
#include <stdbool.h>
#include <stdint.h>
#include "bits.h"

static void check_power_2(void)
{
	// TODO: write tests to check IS_POWER_2() macro
}

static void alignment_tests(void)
{
	// TODO: write tests to check IS_ALIGNED(item, alignment) macro
}

static void extract_bitfield(void)
{
	// TODO: write tests to check the EXTRACT_BITFIELD(variable, high_bit, low_bit)
	// macro
	// (see macro doc)
}

#pragma mark - Public Functions -

int bits_test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(alignment_tests);
	RUN_TEST(check_power_2);
	RUN_TEST(extract_bitfield);
	return UNITY_END();
}
