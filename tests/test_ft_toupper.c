
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>

void test(int (function_under_test)(int c))
{
	(void)function_under_test;
}

int main()
{
	test(&toupper);
	test(&ft_toupper);
}
	