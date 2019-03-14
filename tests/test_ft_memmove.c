
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void *(function_under_test)(void *dst, const void *src, size_t len))
{
	char foo[] = "012345";
	char *bar = &foo[3];

	char *ptr = function_under_test(bar, foo, 3);
	assert(ptr == bar);
	assert(foo[3] == '0');
	assert(foo[5] == '2');

	char *phaedrus = "Phaedrus";
	char buf[0xFF];
	memcpy(buf, phaedrus, strlen(phaedrus));
	function_under_test(buf + 3, buf, strlen(phaedrus));
	assert(strcmp(&buf[3], phaedrus) == 0);
}

int main()
{
	test(&memmove);
	test(&ft_memmove);
}
	