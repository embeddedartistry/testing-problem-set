#include <unity.h>
#include <stdbool.h>
#include <malloc.h>

int freelist_locking_test_suite(void);

#if 0
// This test case is a bit more complex - we're testing a malloc implementation.
//
// The primary goal of this exercise is testing with a side effect:
//	How can you be sure that the malloc_lock() and malloc_unlock() functions
//	actually work?
//	Check freelist.c to find those functions and their documentation.
#endif

#pragma mark - Block Management -

#define MEM_BLOCK_SIZE (1024 * 1024)
static uint8_t mem_block[MEM_BLOCK_SIZE];
size_t mem_block_size = MEM_BLOCK_SIZE;
size_t mem_block_addr = (uintptr_t)mem_block;
size_t mem_block_end_addr = (uintptr_t)mem_block + MEM_BLOCK_SIZE;

static void malloc_locking_test()
{
	malloc_addblock(mem_block, mem_block_size);

	// TODO: allocate a pointer, make sure it is not-null
	// TODO: allocaate a block that is larger than what is available, make sure
	// 	null is returned
	// TODO: can you think of a way to test that free actually works?
	// TODO: how can we test malloc_lock() and malloc_unlock() behavior?
}

#pragma mark - Public Functions -

int freelist_locking_test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(malloc_locking_test);
	return UNITY_END();
}
