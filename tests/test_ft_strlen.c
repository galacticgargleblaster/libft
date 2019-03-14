
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(size_t (function_under_test)(const char *s))
{
	(void)function_under_test;
}

int main()
{
	test(&strlen);
	test(&ft_strlen);
}
	