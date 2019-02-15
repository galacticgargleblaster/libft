
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

void test(void * (function_under_test)(void *,void *))
{
	// do tests here
}

int main()
{
	test(&memmove);
	test(&ft_memmove);
}
	