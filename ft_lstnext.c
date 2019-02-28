/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/27 19:23:29 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates the list lst and returns the FIRST content for which the function
** f returns non-null.
**
** Param. #1 A pointer to the first link of a list.
** Param. #2 The address of a function to apply to each link of a list.
** Return value pointer to content for which function returns non-null, else
** NULL
*/

#include "libft.h"

void	*ft_lstnext(t_list *lst, int (f)(t_list *elem))
{
	while (lst)
	{
		if (f(lst))
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
