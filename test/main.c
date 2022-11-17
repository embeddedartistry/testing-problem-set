/*
 * Copyright © 2022 Embedded Artistry LLC.
 * See LICENSE file for licensing information.
 */

#include "unity.h"

extern int bits_test_suite();
extern int fixed_point_test_suite();
extern int freelist_locking_test_suite();
extern int qsort_test_suite();

static int runAllTests()
{
	int test_status = 0;

	test_status = bits_test_suite();
	test_status |= fixed_point_test_suite();
	test_status |= freelist_locking_test_suite();
	test_status |= qsort_test_suite();

	return test_status;
}

int main(void)
{
	return runAllTests();
}
