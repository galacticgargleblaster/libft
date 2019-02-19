/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 20:18:04 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates the list lst and applies the function f to each link.
**
** Param. #1 A pointer to the first link of a list.
** Param. #2 The address of a function to apply to each link of a list.
** Return value None.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
