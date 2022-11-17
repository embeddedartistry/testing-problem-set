#include <unity.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#pragma mark - Declarations -
static void* input_thunk_int = (void*)0xDEADBEEF;
/* 26 items -- even */
static const char* s[] = {"Bob",	"Alice", "John",   "Ceres",	  "Helga",	 "Drepper", "Emeralda",
						  "Zoran",	"Momo",	 "Frank",  "Pema",	  "Xavier",	 "Yeva",	"Gedun",
						  "Irina",	"Nono",	 "Wiener", "Vincent", "Tsering", "Karnica", "Lulu",
						  "Quincy", "Osama", "Riley",  "Ursula",  "Sam"};
static const char* s_sorted[] = {
	"Alice", "Bob",		"Ceres",  "Drepper", "Emeralda", "Frank",  "Gedun", "Helga",  "Irina",
	"John",	 "Karnica", "Lulu",	  "Momo",	 "Nono",	 "Osama",  "Pema",	"Quincy", "Riley",
	"Sam",	 "Tsering", "Ursula", "Vincent", "Wiener",	 "Xavier", "Yeva",	"Zoran"};

/* 23 items -- odd, prime */
static int n[] = {879045, 394,	99405644, 33434, 232323, 4334,	  5454,	 343,
				  45545,  454,	324,	  22,	 34344,	 233,	  45345, 343,
				  848405, 3434, 3434344,  3535,	 93994,	 2230404, 4334};
static int n_sorted[] = {22,	233,	324,	343,	343,	 394,	  454,	   3434,
						 3535,	4334,	4334,	5454,	33434,	 34344,	  45345,   45545,
						 93994, 232323, 848405, 879045, 2230404, 3434344, 99405644};

#pragma mark - Private Sorting Functions -

static int scmp(void* thunk, const void* a, const void* b)
{
	(void)thunk;
	return strcmp(*(char* const*)a, *(char* const*)b);
}

static int icmp(void* thunk, const void* a, const void* b)
{
	(void)thunk;
	return *(const int*)a - *(const int*)b;
}

static int icmp_thunk_check(void* thunk, const void* a, const void* b)
{
	TEST_ASSERT_EQUAL_PTR(thunk, input_thunk_int);
	return *(const int*)a - *(const int*)b;
}

#pragma mark - Private Test Functions -
static void qsort_r_string_test()
{
	void* thunk = NULL;
	size_t len = sizeof(s) / sizeof(*s);

	qsort_r(s, len, sizeof(*s), thunk, scmp);

	for(size_t i = 0; i < len; i++)
	{
		TEST_ASSERT_EQUAL_INT(strcmp(s[i], s_sorted[i]), 0);
	}
}

static void qsort_r_int_test_thunk_not_null()
{
	void* thunk = input_thunk_int;
	size_t len = sizeof(n) / sizeof(*n);
	qsort_r(n, len, sizeof(*n), thunk, icmp_thunk_check);

	for(size_t i = 0; i < len; i++)
	{
		TEST_ASSERT_EQUAL_INT(n[i], n_sorted[i]);
	}
}

static void qsort_r_int_test()
{
	void* thunk = NULL; // unused in these examples, but we want to test API
	size_t len = sizeof(n) / sizeof(*n);
	qsort_r(n, len, sizeof(*n), thunk, icmp);

	for(size_t i = 0; i < len; i++)
	{
		TEST_ASSERT_EQUAL_INT(n[i], n_sorted[i]);
	}
}

#pragma mark - Public Functions -

int qsort_test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(qsort_r_string_test);
	RUN_TEST(qsort_r_int_test_thunk_not_null);
	RUN_TEST(qsort_r_int_test);
	return UNITY_END();
}
