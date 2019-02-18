
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void *(function_under_test)(void *dst, const void *src, size_t len))
{
	char foo[] = "012345";
	char *bar = &foo[3];

	char *ptr = function_under_test(bar, foo, 3);
	assert(ptr == bar);
	assert(foo[3] == '0');
	assert(foo[5] == '2');
}

int main()
{
	test(&memmove);
	test(&ft_memmove);
}
	