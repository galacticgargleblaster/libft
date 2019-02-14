#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"

#define SOME_MEMORY_SIZE_BYTES 50
#define THE_VALUE 19

void test(void *(memset_under_test)(void *, int, size_t))
{
	char *some_memory = malloc(sizeof(char) * SOME_MEMORY_SIZE_BYTES);
	void *a_pointer = memset_under_test(some_memory, THE_VALUE, SOME_MEMORY_SIZE_BYTES);
	
	assert(a_pointer == some_memory);  // The memset() function returns its first argument.

	// The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.


	for (int i = 0; i < SOME_MEMORY_SIZE_BYTES; i++)
	{
		assert(some_memory[i] == THE_VALUE);
	}

}

int main()
{
	test(&memset);
	test(&ft_memset);
}