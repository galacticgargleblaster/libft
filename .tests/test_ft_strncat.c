
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(char *s1, const char *s2, size_t n))
{
	(void)function_under_test;
}

int main()
{
	test(&strncat);
	test(&ft_strncat);
}
	