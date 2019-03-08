/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/03/08 15:38:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element new at the end of the list.
**
** Param. #1 The address of a pointer to the first link of a list.
** Param. #2 The link to add at the beginning of the list.
** Return value None.
*/

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL || alst == NULL)
		return ;
	else if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = (*alst);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
