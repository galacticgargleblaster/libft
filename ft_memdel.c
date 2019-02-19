/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 20:36:52 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes as a parameter the address of a memory area that needs to be freed 
** with free(3), then puts the pointer to NULL.
**
** Param. #1 A pointer’s address that needs its memory freed and set to NULL.
** Return value None.
*/

#include "libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = 0;
}
