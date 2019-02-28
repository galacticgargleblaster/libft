
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>


typedef struct	test_struct_s
{
	int	hmm;
	void *universe;
}				test_struct_t;


int main()
{
	int *foo = malloc(sizeof(int));
	*foo = 999;
	t_list *lst = ft_lstnewlink(foo);

	// The data is ALIASED, so lst->content should point to the same address.
	assert(lst->content == foo);
	assert(lst->next == NULL);

	test_struct_t *ts = malloc(sizeof(test_struct_t));
	ts->hmm = 92;
	t_list *other_lst = ft_lstnewlink(ts);

	assert(other_lst->content == ts);
	assert(other_lst->next == NULL);
}
	