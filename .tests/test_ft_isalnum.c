
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>

void test(int (function_under_test)(int ))
{
	for (int i = 0; i <= 300; i++)
	{
		if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
			assert(function_under_test(i) == 1);
		else
			assert(function_under_test(i) == 0);
	}
}

int main()
{
	test(&isalnum);
	test(&ft_isalnum);
}
	