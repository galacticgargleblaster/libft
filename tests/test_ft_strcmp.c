
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(int (function_under_test)(const char *s1, const char *s2))
{
	(void)function_under_test;
}

int main()
{
	test(&strcmp);
	test(&ft_strcmp);
}
	