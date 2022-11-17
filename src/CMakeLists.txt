add_library(test_problems STATIC)
target_sources(test_problems PRIVATE
	fixed_point/fixed_point.c
	locking_malloc_freelist/freelist.c
	qsort/qsort.c
)

target_sources(test_problems INTERFACE
	bits/bits_tests.c
	fixed_point/fixed_point_tests.c
	qsort/qsort_r_tests.c
	locking_malloc_freelist/freelist_locking_tests.c
)

target_include_directories(test_problems PUBLIC
	bits
	fixed_point
	locking_malloc_freelist
	qsort
)
