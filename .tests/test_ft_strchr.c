
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(const char *s, int c))
{
	(void)function_under_test;
}

int main()
{
	test(&strchr);
	test(&ft_strchr);
}
	