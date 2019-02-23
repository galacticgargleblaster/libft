/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 11:22:46 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pushes existing content onto a list.  If the list doesn't yet exist
** (lst == NULL), instantiate a new list to hold the content.
**
** Param. #1 The address of a pointer to the first link of a list.
** Param. #2, #3 the content and content size.
** Return value the address of the first link of the list
*/

#include "libft.h"

t_list	*ft_lstpush(t_list *lst, void const *content, size_t content_size)
{
	if (lst == NULL)
		return (ft_lstnew(content, content_size));
	else
	{
		ft_lstadd(&lst, ft_lstnew(content, content_size));
		return (lst);
	}
}
