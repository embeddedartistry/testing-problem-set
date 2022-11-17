#include <unity.h>
#include <stdbool.h>
#include <malloc.h>

#define ALLOCATION_TEST_COUNT 768

static void* ptr_array[ALLOCATION_TEST_COUNT];

bool malloc_lock_called = false;
bool malloc_unlock_called = false;
unsigned malloc_locked_count;
unsigned malloc_unlocked_count;

#pragma mark - Block Management -

#define MEM_BLOCK_SIZE (1024 * 1024)
static uint8_t mem_block[MEM_BLOCK_SIZE];
size_t mem_block_size = MEM_BLOCK_SIZE;
size_t mem_block_addr = (uintptr_t)mem_block;
size_t mem_block_end_addr = (uintptr_t)mem_block + MEM_BLOCK_SIZE;

void malloc_lock()
{
	malloc_lock_called = true;
	malloc_locked_count++;
}

void malloc_unlock()
{
	malloc_unlock_called = true;
	malloc_unlocked_count++;
}

static void malloc_locking_test()
{
	malloc_locked_count = 0;
	malloc_unlocked_count = 0;

	malloc_addblock(mem_block, mem_block_size);

	void* ptr = malloc(1024);

	TEST_ASSERT_NOT_NULL(ptr);
	TEST_ASSERT(((uintptr_t)ptr >= mem_block_addr) && ((uintptr_t)ptr < mem_block_end_addr));

	free(ptr);

	// Check request too large
	ptr = malloc(2 * mem_block_size);
	TEST_ASSERT_NULL(ptr);

	for(int i = 0; i < ALLOCATION_TEST_COUNT; i++)
	{
		ptr_array[i] = malloc(1024);
		TEST_ASSERT_NOT_NULL(ptr_array[i]);
		TEST_ASSERT(((uintptr_t)ptr_array[i] >= mem_block_addr) &&
					((uintptr_t)ptr_array[i] < mem_block_end_addr));
	}

	// Cleanup
	for(int i = 0; i < ALLOCATION_TEST_COUNT; i++)
	{
		free(ptr_array[i]);
	}

	// Run test again, will not fail if our memory has been returned!
	for(int i = 0; i < ALLOCATION_TEST_COUNT; i++)
	{
		ptr_array[i] = malloc(1024);
		TEST_ASSERT_NOT_NULL(ptr_array[i]);
		TEST_ASSERT(((uintptr_t)ptr_array[i] >= mem_block_addr) &&
					((uintptr_t)ptr_array[i] < mem_block_end_addr));
	}

	// Cleanup
	for(int i = 0; i < ALLOCATION_TEST_COUNT; i++)
	{
		free(ptr_array[i]);
	}

	TEST_ASSERT_TRUE(malloc_lock_called);
	TEST_ASSERT_TRUE(malloc_unlock_called);
	TEST_ASSERT_TRUE(malloc_locked_count != 0);
	TEST_ASSERT_TRUE(malloc_unlocked_count != 0);
	TEST_ASSERT_TRUE(malloc_locked_count == malloc_unlocked_count);
}

#pragma mark - Public Functions -

int freelist_locking_test_suite(void)
{
	UNITY_BEGIN();
	RUN_TEST(malloc_locking_test);
	return UNITY_END();
}
