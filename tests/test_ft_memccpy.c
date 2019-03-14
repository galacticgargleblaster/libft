
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void *(function_under_test)(void *dst, const void *src, int c, size_t n))
{
	const char foo[] = "012345";
	char bar[] = "------";

	char *ptr = function_under_test(bar, foo, '2', 6);
	assert(bar[0] == '0');
	assert(bar[2] == '2');
	assert(ptr == &bar[3]);
}

int main()
{

	test(&memccpy);
	test(&ft_memccpy);
}
	