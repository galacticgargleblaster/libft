/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 13:36:17 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pops an element from the beginning of a list, returning a pointer to the
** popped content.
**
** Param. #1 The address of a pointer to the first link of a list.
** Returns a pointer to the popped content.
*/

#include "libft.h"
#include <stdlib.h>

void	*ft_lstpop(t_list **list_head)
{
	void	*content;
	t_list	*pop_me;

	if (list_head == NULL || *list_head == NULL)
		return (NULL);
	pop_me = *list_head;
	content = pop_me->content;
	*list_head = pop_me->next;
	free(pop_me);
	return (content);
}
