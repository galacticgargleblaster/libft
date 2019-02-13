#include "../src/ft_strdup.c"
#include "../src/ft_itoa.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	assert(strcmp(ft_itoa(-12312983192), "-12312983192") == 0);
}
