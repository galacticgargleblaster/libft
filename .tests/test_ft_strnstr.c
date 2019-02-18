
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(const char *haystack, const char *needle, size_t len))
{
	(void)function_under_test;
}

int main()
{
	test(&strnstr);
	test(&ft_strnstr);
}
	