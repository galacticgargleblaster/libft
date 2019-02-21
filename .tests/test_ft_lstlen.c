
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

int main()
{
	t_list *lst = NULL; 

	int *foo = malloc(sizeof(int));
	int *bar = malloc(sizeof(int));

	assert(ft_lstlen(&lst) == 0);	
	ft_lstadd(&lst, ft_lstnew(foo, sizeof(int)));
	assert(ft_lstlen(&lst) == 1);	
	ft_lstadd(&lst, ft_lstnew(bar, sizeof(int)));
	assert(ft_lstlen(&lst) == 2);	
}
	