/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 20:24:52 by nkirkby          ###   ########.fr       */
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


char	*ft_itoa(int n)
{
	long	tmpn;
	long	len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmpn = (long)n;
	len = 2;
	while (tmpn /= 10)
		len++;
	len += (n < 0);
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
