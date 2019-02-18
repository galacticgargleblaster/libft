
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>

void test(int (function_under_test)(int ))
{
	assert(function_under_test('1') == 1);	
	assert(function_under_test('9') == 1);
	assert(function_under_test(0) == 0);
	assert(function_under_test('a') == 0);
}

int main()
{
	test(&isdigit);
	test(&ft_isdigit);
}
	