
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../libft.h"
#include <string.h>


int main()
{
	int a = 3;
	int b = 4;
	int c = 5;

	t_list *node_a = ft_lstnewlink(&a);
	t_list *node_b = ft_lstnewlink(&b);
	t_list *node_c = ft_lstnewlink(&c);

	ft_lstaddback(&node_a, node_b);
	ft_lstaddback(&node_a, node_c);

	assert(node_a->next == node_b);
	assert(node_b->next == node_c);
}
	