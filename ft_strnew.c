/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 16:42:42 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
** Each character of the string is initialized at ’\0’. If the allocation fails
** the function returns NULL.
**
** Param. #1 The size of the string to be allocated.
** Return value The string allocated and initialized to 0
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	fresh = ft_memalloc(size + 1);
	return (fresh);
}
