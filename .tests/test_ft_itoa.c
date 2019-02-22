#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../libft.h"

int main()
{
	char *str = ft_itoa(-123129);
	assert(strcmp(str, "-123129") == 0);
}
