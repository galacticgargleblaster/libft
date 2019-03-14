
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void *(function_under_test)(void *b, int c, size_t len))
{
	(void)function_under_test;
}

int main()
{
	test(&memset);
	test(&ft_memset);
}
	