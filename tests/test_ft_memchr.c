
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void *(function_under_test)(const void *s, int c, size_t n))
{
	char foo[] = "012345";

	char *ptr = function_under_test(foo, '3', strlen(foo));
	assert(ptr == &foo[3]);

	char *bar = "\x01\xf0\x00";
	char *ptr2 = function_under_test(bar, 0xf0, strlen(bar));
	assert(ptr2 == &bar[1]);
}

int main()
{
	test(&memchr);
	test(&ft_memchr);
}
	