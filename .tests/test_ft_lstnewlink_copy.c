
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
	t_list *lst = ft_lstnewlink_copy(foo, sizeof(int));

	// The data is COPIED, so lst->content should point to a different copy of the integer "999" than foo does.
	assert(lst->content != foo);
	// the copied values should be identical.
	assert((*(int *)lst->content) == *foo);
	assert(lst->next == NULL);

	test_struct_t *ts = malloc(sizeof(test_struct_t));
	ts->hmm = 92;
	t_list *other_lst = ft_lstnewlink_copy(ts, sizeof(test_struct_t));

	assert(other_lst->content != ts);
	assert(memcmp(other_lst->content, ts, sizeof(test_struct_t)) == 0);
	assert(other_lst->next == NULL);
}
	