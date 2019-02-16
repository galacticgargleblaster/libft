
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>
#include <stdio.h>

void test(int (function_under_test)(int ))
{
	assert(function_under_test('a') == 1);
	assert(function_under_test('0') == 1);
	assert(function_under_test(0) == 0);
}

int main()
{
	printf("foobar\n\n\n\n");
	printf("does this not get flushed or something??\r");
	test(&isascii);
	printf("ft_isascii\t");
	test(&ft_isascii);
}
	