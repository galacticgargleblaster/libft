
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(int (function_under_test)(const void *s1, const void *s2, size_t n))
{
	char foo[] = "012345";
	char bar[] = "012245";

	int diff = function_under_test(foo, bar, 6);
	assert(diff == 1);
}

int main()
{
	test(&memcmp);
	test(&ft_memcmp);
}
	