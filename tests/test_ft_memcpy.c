
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void *(function_under_test)(void *dst, const void *src, size_t n))
{
	char foo[] = "012345";
	char bar[] = "-------";
	char *ptr = function_under_test(bar, foo, 6);

	assert(ptr == bar);
	assert(bar[0] == '0');
	assert(bar[5] == '5');
	assert(bar[6] == '-');
}

int main()
{
	test(&memcpy);
	test(&ft_memcpy);
}
	