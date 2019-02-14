#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"

#define SOME_MEMORY_SIZE_BYTES 50

void test(void (function_under_test)(void *, size_t))
{
	char *some_memory = malloc(sizeof(char) * SOME_MEMORY_SIZE_BYTES);
	function_under_test(some_memory, SOME_MEMORY_SIZE_BYTES);
	
	//The bzero() function writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.

	for (int i = 0; i < SOME_MEMORY_SIZE_BYTES; i++)
	{
		assert(some_memory[i] == 0);
	}

}

int main()
{
	test(&bzero);
	test(&ft_bzero);
}