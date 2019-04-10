/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/04/10 00:04:29 by student          ###   ########.fr       */
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

#define IS_NONPRINTING(X) ((X == '\t' || X == '\n' || X == '\v' || X == '\r'))
#define IS_SPACE(X) (( X == ' ' || IS_NONPRINTING(X)))
#define IS_SIGN(X) ((X == '+' || X == '-'))
#define ABS(X) ((X) < 0 ? -(X) : (X))

static char		int_to_char(int i)
{
	char		c;

	if (i <= 9)
		c = '0' + i;
	else
		c = 'A' + i - 10;
	return (c);
}

static size_t	number_of_digits_needed_to_express(long long value, int base)
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

char			*ft_lltoa_base(long long value, int base)
{
	size_t		idx;
	char		*buf;
	char		*tmp;

	if (base > 16 || base < 2)
		return (0);
	idx = number_of_digits_needed_to_express(value, base);
	if ((buf = ft_memalloc(idx + 1 + (value < 0))) == NULL)
		return (NULL);
	if (value < 0)
	{
		buf[0] = '-';
		tmp = buf + 1;
	}
	else
		tmp = buf;
	while (idx-- > 0)
	{
		tmp[idx] = int_to_char(ABS(value % base));
		value /= base;
	}
	return (buf);
}

static size_t	number_of_digits_needed_to_express_unsigned(
						unsigned long long value, int base)
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

char			*ft_ulltoa_base(unsigned long long value, int base)
{
	size_t		idx;
	char		*buf;
	char		*tmp;

	if (base > 16 || base < 2)
		return (0);
	idx = number_of_digits_needed_to_express_unsigned(value, base);
	if ((buf = ft_memalloc(idx + 1)) == NULL)
		return (NULL);
	tmp = buf;
	while (idx-- > 0)
	{
		tmp[idx] = int_to_char(ABS(value % base));
		value /= base;
	}
	return (buf);
}
