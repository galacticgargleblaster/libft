
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>

void test(int (function_under_test)(int ))
{
	assert(function_under_test('a') == 1);
	assert(function_under_test('z') == 1);
	assert(function_under_test('0') == 0);
	assert(function_under_test('!') == 0);
	assert(function_under_test(0) == 0);
}

int main()
{
	test(&isalpha);
	test(&ft_isalpha);
}
	