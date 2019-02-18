
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(const char *s1))
{
	(void)function_under_test;
}

int main()
{
	test(&strdup);
	test(&ft_strdup);
}
	