/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 12:06:57 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates a list lst and applies the function f to each link to create a
** "fresh” list (using malloc(3)) resulting from the successive applications
** of f. If the allocation fails, the function returns NULL.
**
** Param. #1 A pointer’s to the first link of a list.
** Param. #2 The address of a function to apply to each link of a list.
** Return value The new list.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *copy;
	t_list *ptr;

	if (lst == NULL)
		return (NULL);
	ptr = f(lst);
	lst = lst->next;
	copy = ptr;
	while (lst)
	{
		ptr->next = f(lst);
		ptr = ptr->next;
		lst = lst->next;
	}
	return (copy);
}
