
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(char *dst, const char *src))
{
	char dst[40];

	char *str = "Socrates was Plato's student\n\r";
	char *ret = function_under_test(dst, str);
	assert(ret == dst);
	assert(strcmp(dst, str) == 0);
}

int main()
{
	test(&strcpy);
	test(&ft_strcpy);
}
	