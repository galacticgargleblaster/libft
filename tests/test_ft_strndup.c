
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(const char *s1, size_t n))
{
	char *hmm = "Hmm..";
	char *result = function_under_test(hmm, 2);
	assert(strcmp(result, "Hm") == 0);
	assert(result != hmm);
}

int main()
{
	test(&strndup);
	test(&ft_strndup);
}
	