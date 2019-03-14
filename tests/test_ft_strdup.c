
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(char *(function_under_test)(const char *s1))
{
	char *hmm = "Hmm..";
	char *result = function_under_test(hmm);
	assert(strcmp(result, hmm) == 0);
	assert(result != hmm);
}

int main()
{
	test(&strdup);
	test(&ft_strdup);
}
	