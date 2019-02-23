#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

int main()
{
	char *str = ft_itoa(-123129);
	assert(strcmp(str, "-123129") == 0);


	char *str2 = ft_itoa(-2147483648);
	assert(strcmp(str2, "-2147483648") == 0);
}
