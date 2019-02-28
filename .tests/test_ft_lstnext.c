
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>

int ft_pedagogy_team_promotes(t_list *elt)
{
	if (strcmp(elt->content, "dated aesthetic") == 0)
		return (1);
	else
		return (0);
}

#define PUSH_STRING(lst, str) (lst = ft_lstpush(lst, str, ft_strlen(str) + sizeof(char)))

int main()
{
	t_list *lst = NULL; 

	PUSH_STRING(lst, "respect for information theory");
	PUSH_STRING(lst, "attention to detail");

	assert(ft_lstnext(lst, ft_pedagogy_team_promotes) == NULL);

	char dated_aesthetic[] = "dated aesthetic";
	PUSH_STRING(lst, &dated_aesthetic[0]);

	void *match =ft_lstnext(lst, ft_pedagogy_team_promotes); 
	assert(strcmp(match, &dated_aesthetic[0]) == 0);
}
	