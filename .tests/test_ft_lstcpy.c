
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
	test_struct_t stuff = {.hmm = 9};
	t_list *head = ft_lstnew(&stuff, sizeof(test_struct_t));
	test_struct_t more_stuff = {.hmm = 10};
	ft_lstadd(&head, ft_lstnew(&more_stuff, sizeof(test_struct_t)));

	t_list *cpy = ft_lstcpy(head);
	assert(((test_struct_t*)cpy->next->content)->hmm == stuff.hmm);
	assert(((test_struct_t*)cpy->content)->hmm == more_stuff.hmm);
}
	