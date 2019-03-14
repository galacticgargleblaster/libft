
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(const char *s, int c))
{
	char foo[] = "asf";

	assert(function_under_test(foo, 'a') == &foo[0]);
	assert(function_under_test(foo, 0) == &foo[3]);
}

int main()
{
	test(&strchr);
	test(&ft_strchr);
}
	