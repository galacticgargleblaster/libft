
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

#define PUSH_STRING(lst, str) (lst = ft_lstpush(lst, str))

int main()
{
	t_list *lst = NULL;
	char *a = "AAA";
	char *b = "BBB";
	char *c = "CCC";
	PUSH_STRING(lst, a);
	PUSH_STRING(lst, b);
	PUSH_STRING(lst, c); 

	char *hmm = ft_lstremove(&lst, b);
	assert(hmm == b);
	assert(strcmp((char *)lst->content, "CCC") == 0);	
	assert(strcmp((char *)lst->next->content, "AAA") == 0);

	char *should_be_null = ft_lstremove(&lst, b);
	assert(should_be_null == NULL);
	assert(strcmp((char *)lst->content, "CCC") == 0);	
	assert(strcmp((char *)lst->next->content, "AAA") == 0);

	char *should_be_a = ft_lstremove(&lst, a);
	assert(should_be_a == a);
	assert(lst != NULL);

	char *should_be_c = ft_lstremove(&lst, c);
	assert(should_be_c == c);
	assert(lst == NULL);
}