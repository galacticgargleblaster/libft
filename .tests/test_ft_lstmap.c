
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

t_list *times_two(t_list *elt)
{
	int *content = malloc(sizeof(int));
	t_list *new;

	*content = *(int *)(elt->content) * 2;
	new = ft_lstnew(content, sizeof(int));
	return (new);
}

int main()
{
	t_list *lst = NULL; 

	int *foo = malloc(sizeof(int));
	int *bar = malloc(sizeof(int));

	*foo = 4;
	*bar = 21;

	ft_lstadd(&lst, ft_lstnew(foo, sizeof(int)));
	ft_lstadd(&lst, ft_lstnew(bar, sizeof(int)));


	t_list *fresh_lst = ft_lstmap(lst, times_two);
	assert(*(int *)fresh_lst->content == 42);
	assert(*(int *)fresh_lst->next->content == 8);
}
	