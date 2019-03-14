
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>
#include <stdio.h>

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

	// Even though the buffer is too small, strlen(dst) + strlen(src) should be returned
	char too_small[4] = "";
	size_t size = function_under_test(too_small, "too long", 4);
	assert(size == 8);

#define		STRING_1	"a\0I"
#define		STRING_2	"there is no starsss in the"

	// this is some particularly weird behavior.
	// the entire has_null_byte string should get copied
	// the returned length should be 3.
				char	*str = STRING_1;
			char	buff1[0xF00] = STRING_2;
	size_t	max = strlen(str) + 4;

	size_t r = function_under_test(buff1, str, max);
	// in the case that dstsize is less than the length of destination string
	// the function should return the length of the source string plus dstsize
	assert(r == 6); 
}

void	extra_stuff_from_qperez_maintest()
{
	char		dest[50] = {0};
	char		dest2[50] = {0};
	size_t		i, j, k;

	assert(strlcat(dest, "Hello ", 4) == ft_strlcat(dest2, "Hello ", 4));
	memset(dest, 0, sizeof(dest));
	memset(dest2, 0, sizeof(dest));
	j = strlcat(dest, "Hello ", 4);
	k = ft_strlcat(dest2, "Hello ", 4);
	assert(strcmp(dest, dest2) == 0);
	assert(j == k);
	j = strlcat(dest, "Hello ", 1);
	k = ft_strlcat(dest2, "Hello ", 1);
	assert(strcmp(dest, dest2) == 0);
	assert(j == k);
	i = 0;
	while (i < 6)
	{
		dest[4 + i] = 'z';
		dest2[4 + i] = 'z';
		++i;
	}
	j = strlcat(dest, "abc", 6);
	k = ft_strlcat(dest2, "abc", 6);
	assert(strcmp(dest, dest2) == 0);
	assert(j == k);
}

int main()
{
	test(&strlcat);
	test(&ft_strlcat);
	extra_stuff_from_qperez_maintest();
}

