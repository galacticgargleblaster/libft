
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

#define PUSH_STRING(lst, str) (lst = ft_lstpush(lst, str))

int main()
{
	t_list *lst = NULL; 
	char *b = "BBB";
	PUSH_STRING(lst, "AAA");
	PUSH_STRING(lst, b);
	PUSH_STRING(lst, "CCC"); 

	char *hmm = ft_lstremove(&lst, b);
	assert(hmm == b);
	assert(strcmp((char *)lst->content, "CCC") == 0);	
	assert(strcmp((char *)lst->next->content, "AAA") == 0);
}