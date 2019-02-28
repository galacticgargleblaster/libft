/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/28 14:56:19 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a new link, aliasing the argument content
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewlink(void const *content)
{
	t_list	*link;

	link = malloc(sizeof(t_list));
	if (link)
	{
		link->next = NULL;
		link->content = (void *)content;
	}
	return (link);
}
