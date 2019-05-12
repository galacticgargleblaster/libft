
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>

int main()
{
	assert(ft_endswith("foobar", 'r'));
	assert(ft_endswith("foobar", 't') == 0);
	assert(ft_endswith("", 0) == 0);
	assert(ft_endswith("", 't') == 0);
}
	