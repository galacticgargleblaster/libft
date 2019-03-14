
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(const char *haystack, const char *needle))
{
	char 	h0[] = "FOFOO";
	char	n0[] = "FOO";

	char	*result = function_under_test(h0, n0);
	assert(result == &h0[2]);

	char	h1[] = "hmm FF ok FF";
	char	n1[] = "FF";

	result = function_under_test(h1, n1);
	assert(result == &h1[4]);

	result = function_under_test(n1, h1);
	assert(result == NULL);
}

int main()
{
	test(&strstr);
	test(&ft_strstr);
}
	