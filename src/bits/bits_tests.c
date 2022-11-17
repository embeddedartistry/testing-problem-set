#include <unity.h>
#include <stdbool.h>
#include <stdint.h>
#include "bits.h"

static void check_power_2(void)
{
	TEST_ASSERT_TRUE(IS_POWER_2(0));
	TEST_ASSERT_TRUE(IS_POWER_2(1));
	TEST_ASSERT_TRUE(IS_POWER_2(2));
	TEST_ASSERT_TRUE(IS_POWER_2(4));
	TEST_ASSERT_FALSE(IS_POWER_2(3));
	TEST_ASSERT_FALSE(IS_POWER_2(1023));
}

static void alignment_tests(void)
{
	const uint8_t x = 8;
	TEST_ASSERT_TRUE(IS_ALIGNED(x, 8));
	TEST_ASSERT_TRUE(IS_ALIGNED((uintptr_t)&x, 1));

	uint32_t y;
	TEST_ASSERT_TRUE(IS_ALIGNED((uintptr_t)&y, 4));

	y = 7;
	TEST_ASSERT_FALSE(IS_ALIGNED(y, 8));
}

static void extract_bitfield(void)
{
	int val = 0b11010011;
	// cppcheck-suppress constArgument
	TEST_ASSERT(EXTRACT_BITFIELD(val, 7, 5) == 0b110);
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
