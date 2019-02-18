
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(size_t (function_under_test)(char *, const char *, size_t dstsize))
{
	char buf[20];
	char *hmm = "hmm";

	memset(buf, 0, 20);
	function_under_test(buf, hmm, strlen(hmm) + 1);
	assert(strcmp(hmm, buf) == 0);

	// catting another "hmm" should make the strings no longer equal
	function_under_test(buf, hmm, 2 * strlen(hmm) + 1);
	assert(strcmp(hmm, buf) != 0);

	char *src = "abc";
	char dst[20];
	strcpy(dst, "___");

	// with dstsize 0, the destination string should be unchanged
	function_under_test(dst, src, 0);
	assert(strcmp(dst, "___") == 0);

	// with dstsize 5, one character should be appended
	// as well as one null byte
	function_under_test(dst, src, 5);
	assert(strcmp(dst, "___a") == 0);

	char too_small[4] = "";
	size_t size = function_under_test(too_small, "too long", 4);
	assert(size == 8);

}

int main()
{
	test(&strlcat);
	test(&ft_strlcat);
}
	