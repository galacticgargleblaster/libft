/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/04/09 23:26:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument.  Negative numbers must be
** supported. If the allocation fails, the function returns NULL.
**
** Param. #1 The integer to be transformed into a string.
** Return value The string representing the integer passed as argument.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	return (ft_lltoa_base((long long)(value), base));
}

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}
