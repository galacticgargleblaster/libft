/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/22 13:36:22 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Param. #1 a pointer to the first link to be copied.
** Return value the first link of the copied list.
*/

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstcpy(t_list *lst)
{
	t_list	*elt;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(lst->content, lst->content_size);
	head->next = NULL;
	elt = head;
	while (lst->next)
	{
		lst = lst->next;
		elt->next = ft_lstnew(lst->content, lst->content_size);
		elt = elt->next;
	}
	return (head);
}
