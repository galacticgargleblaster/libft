
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void *(function_under_test)(const void *s, int c, size_t n))
{
	char foo[] = "012345";

	char *ptr = function_under_test(foo, '3', 6);
	assert(ptr == &foo[3]);
}

int main()
{
	test(&memchr);
	test(&ft_memchr);
}
	