/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/21 14:18:58 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Calculates length of a list.
**
** Param. #1 The address of a pointer to the first link of a list.
** Return value int, the length of the list
*/

#include "libft.h"

int	ft_lstlen(t_list **lst_head)
{
	size_t	len;
	t_list	*elt;

	len = 0;
	elt = (lst_head ? *lst_head : NULL);
	while (elt)
	{
		elt = elt->next;
		len++;
	}
	return (len);
}
