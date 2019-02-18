
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(char *dst, const char *src))
{
	(void)function_under_test;
}

int main()
{
	test(&strcpy);
	test(&ft_strcpy);
}
	