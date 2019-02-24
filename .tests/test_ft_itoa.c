#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

#define ASSERT_STR_EQUAL(X, Y) (assert(strcmp(X, Y) == 0))

int main()
{
	char *str = ft_itoa(-123129);
	ASSERT_STR_EQUAL(str, "-123129");


	char *str2 = ft_itoa(-2147483648);
	ASSERT_STR_EQUAL(str2, "-2147483648");
	
	char *str3 = ft_itoa(0);
	ASSERT_STR_EQUAL(str3, "0");

	char *str4 = ft_itoa(123);
	ASSERT_STR_EQUAL(str4, "123");

	char *str5 = ft_itoa(-0);
	ASSERT_STR_EQUAL(str5, "0");
}
