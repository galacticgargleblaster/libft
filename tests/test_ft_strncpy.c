
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(char *dst, const char *src, size_t len))
{
	(void)function_under_test;
}

int main()
{
	test(&strncpy);
	test(&ft_strncpy);
}
	