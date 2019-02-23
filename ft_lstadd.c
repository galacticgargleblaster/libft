/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 12:15:05 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element new at the beginning of the list.
**
** Param. #1 The address of a pointer to the first link of a list.
** Param. #2 The link to add at the beginning of the list.
** Return value None.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new == NULL || alst == NULL)
		return ;
	else if (*alst == NULL)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
