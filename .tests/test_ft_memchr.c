
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void * (function_under_test)(void *,int ))
{
	// do tests here
}

int main()
{
	test(&memchr);
	test(&ft_memchr);
}
	