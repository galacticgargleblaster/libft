
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(size_t (function_under_test)(char *restrict, const char *restrict, size_t dstsize))
{
	(void)function_under_test;
}

int main()
{
	test(&strlcat);
	test(&ft_strlcat);
}
	