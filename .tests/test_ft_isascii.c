
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>
#include <stdio.h>

void test(int (function_under_test)(int ))
{
	assert(function_under_test(0) == 1);
	assert(function_under_test('\177') == 1);
}

int main()
{
	test(&isascii);
	test(&ft_isascii);
}
	