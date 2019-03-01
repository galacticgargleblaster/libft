/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/28 18:34:25 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Removes the link that points to content, and then return the content.
** If no such link exists, return NULL.
*/

#include "libft.h"
#include <stdlib.h>

void	*ft_lstremove(t_list **alst, void *content)
{
	t_list	*elt;
	t_list	*prev;

	prev = NULL;
	elt = *alst;
	while (elt)
	{
		if (elt->content == content)
		{
			if (prev == NULL)
				*alst = elt->next;
			else
				prev->next = elt->next;
			free(elt);
			return (content);
		}
		prev = elt;
		elt = elt->next;
	}
	return (NULL);
}
