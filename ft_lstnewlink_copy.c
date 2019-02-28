/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/28 14:45:35 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The variables content
** and content_size of the new link are initialized by copy of the parameters
** of the function. If the parameter content is nul, the variable content is
** initialized to NULL and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t. The variable next is initialized to
** NULL. If the allocation fails, the function returns NULL.
**
** Param. #1 The content to put in the new link.
** Param. #2 The size of the content of the new link.
** Return value The new link.
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewlink_copy(void const *content, size_t content_size)
{
	t_list	*link;

	link = malloc(sizeof(t_list));
	if (link)
	{
		link->next = NULL;
		if (content && content_size)
		{
			link->content = ft_memalloc(content_size);
		}
		else
		{
			link->content = NULL;
		}
		if (link->content)
			ft_memcpy(link->content, content, content_size);
	}
	return (link);
}
