/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/14 12:33:35 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#define IS_SIGN(X) (X == '+' || X == '-')

/*
** The real atoi:
** - parses + and - signs
** - ignores leading zeros
** - starts parsing if it encounters a + sign, - sign,
** - stops parsing if it encounters a non-digit
** - overflows if the number is larger than an int
*/

int	ft_atoi(char *str)
{
	long	output;
	int		sign;

	output = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (!(IS_DIGIT(*str) || IS_SIGN(*str)))
		return (0);
	if (IS_SIGN(*str))
		sign = *str++ == '-' ? -1 : 1;
	if (!IS_DIGIT(*str))
		return (0);
	while (*str && IS_DIGIT(*str))
	{
		output *= 10;
		output += (int)(*str++ - '0');
	}
	output *= sign;
	return (int)(output);
}

/*
**	This version of atoi mutates a pointed-to integer
**	Returns 0 if succesful, other if the argument is invalid.
*/

int	ft_atoi_ptr(char *str, long *out)
{
	long	output;
	int		sign;

	output = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (!(IS_DIGIT(*str) || IS_SIGN(*str)))
		return (-1);
	if (IS_SIGN(*str))
		sign = *str++ == '-' ? -1 : 1;
	if (!IS_DIGIT(*str))
		return (-1);
	while (*str && IS_DIGIT(*str))
	{
		output *= 10;
		output += (int)(*str++ - '0');
	}
	output *= sign;
	*out = (output);
	return (0);
}
