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

	char *str6 = ft_itoa(-623);
	ASSERT_STR_EQUAL(str6, "-623");

	char *str7 = ft_lltoa_base(__LONG_LONG_MAX__, 10);
	ASSERT_STR_EQUAL(str7, "9223372036854775807");

	long long largest_negative = -9223372036854775807;
	largest_negative -= 1;
	char *str8 = ft_lltoa_base(largest_negative, 10);
	ASSERT_STR_EQUAL(str8, "-9223372036854775808");
	
	char *str9 = ft_ulltoa_base(18446744073709551615ULL, 10);
	ASSERT_STR_EQUAL(str9, "18446744073709551615");
}
