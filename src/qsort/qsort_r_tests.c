#include <unity.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#if 0
void qsort_r(void *base, size_t nel, size_t width,
    int (*compar)(void *context, const void *x, const void *y),
    void *thunk);

  The qsort_r() function performs the same operation as the qsort() function,
  differing in the addition of the thunk argument, which may hold a user-defined
  alue. This value is passed without interpretation to the comparison function,
  and can be used to pass information between the caller and the comparison function.
#endif

#pragma mark - Declarations -

/* 23 items -- odd, prime */
static int n[] = {879045, 394,	99405644, 33434, 232323, 4334,	  5454,	 343,
				  45545,  454,	324,	  22,	 34344,	 233,	  45345, 343,
				  848405, 3434, 3434344,  3535,	 93994,	 2230404, 4334};
static int n_sorted[] = {22,	233,	324,	343,	343,	 394,	  454,	   3434,
						 3535,	4334,	4334,	5454,	33434,	 34344,	  45345,   45545,
						 93994, 232323, 848405, 879045, 2230404, 3434344, 99405644};

#pragma mark - Private Sorting Functions -

// Return negative val for a < b, 0 for a == b, positive val for a > b
static int icmp(void* thunk, const void* a, const void* b)
{
	// TODO: implement a comparision
}

#pragma mark - Private Test Functions -

static void qsort_r_int_test()
{
	// TODO: write a test that sorts the "n" array and makes sure that it matches
	// the "n_sorted" array
}

static void qsort_r_int_test_thunk_not_null()
{
	// TODO: write a test that sorts the "n" array and makes sure that it matches
	// the "n_sorted" array
	// But this time, also check the "thunk" parameter is faithfully passed
	// to the comparision function.
}

#pragma mark - Public Functions -

int qsort_test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(qsort_r_int_test_thunk_not_null);
	RUN_TEST(qsort_r_int_test);
	return UNITY_END();
}
