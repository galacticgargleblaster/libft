/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 13:34:35 by nkirkby          ###   ########.fr       */
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

#define IS_SPACE(X) ((X == '\t' || X == ' ' || X == '\n' || X == '\v' || X == '\r'))
#define IS_SIGN(X) ((X == '+' || X == '-'))
#define ABS(X) (X < 0 ? -X : X)

static char		int_to_char(int i)
{
	char 		c;

	if (i <= 9)
		c = ('0' + i);
	else
		c =  ('A' + i - 10);
	return (c);
}

static size_t	number_of_digits_needed_to_express(int value, int base)
{
	size_t		size;

	size = 0;
	while (value || size == 0)
	{
		value /= base;
		size += 1;
	}
	return (size);
}

char			*ft_itoa_base(int value, int base)
{
	size_t		idx;
	char		*buf;

	if (base > 16 || base < 2)
		return (0);
	idx = number_of_digits_needed_to_express(value, base);
	idx = (value < 0 ? idx + 1 : idx);
	if ((buf = ft_memalloc(idx + 1)) == NULL)
		return (NULL);
	buf[0] = (value < 0 ? '-' : '\0');
	while (buf[--idx] == 0)
	{
		buf[idx] = int_to_char(ABS(value % base));
		value /= base;
	}
	return (buf);
}
