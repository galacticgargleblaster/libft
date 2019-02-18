/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 15:27:07 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define IS_SIGN(X) (X == '+' || X == '-')
#define IS_WHITESPACE(X) (ft_strchr("\t\v\f\r\n ", (int)X) != NULL)
#define LONG_MAX 9223372036854775807

/*
** The real atoi:
** - parses + and - signs
** - ignores leading zeros
** - starts parsing if it encounters a + sign, - sign,
** - stops parsing if it encounters a non-digit
** - overflows if the number is larger than an int
**
** https://github.com/alelievr/libft-unit-test revealed behavior of atoi
** when fed values outside the range [LONG_MIN, LONG_MAX].  They are tabulated
** below:
**
** atoi result    			input
** 	-6				9223372036854775802
** 	-5				9223372036854775803
** 	-4				9223372036854775804
** 	-3				9223372036854775805
** 	-2				9223372036854775806
** 	-1				9223372036854775807  <<< LONG_MAX
** 	-1				9223372036854775808
** 	-1				9223372036854775809
**	-1				9223372036854775810
**	-1				9223372036854775811
**	6				-9223372036854775802
**	5				-9223372036854775803
**	4				-9223372036854775804
**	3				-9223372036854775805
**	2				-9223372036854775806
**	1				-9223372036854775807
**	0				-9223372036854775808  <<<  LONG_MIN
**	0				-9223372036854775809
**	0				-9223372036854775810
**	0				-9223372036854775811
*/

int	ft_atoi(const char *str)
{
	unsigned long long	output;
	int					sign;

	output = 0;
	sign = 1;
	while (IS_WHITESPACE(*str))
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
		if (output >= LONG_MAX && sign == 1)
			return (-1);
		else if (output > LONG_MAX && sign == -1)
			return (0);
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
