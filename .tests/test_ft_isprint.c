
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <ctype.h>


int main()
{
	for (int i = 0; i < 255; i++)
	{
		assert(ft_isprint(i) == isprint(i));
	}
}
	