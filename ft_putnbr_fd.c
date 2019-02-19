/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 19:58:00 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the integer n to the file descriptor fd.
**
** Param. #1 The integer to print.
** Param. #2 The file descriptor.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[12];
	int		i;
	int		is_negative;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	i = 0;
	is_negative = (n < 0);
	while (n != 0)
	{
		num[i] = ((n % 10) >= 0 ? (n % 10) : -(n % 10)) + '0';
		if (n /= 10)
			i++;
	}
	if (is_negative)
	{
		i++;
		num[i] = '-';
	}
	while (i-- >= 0)
		ft_putchar_fd(num[i + 1], fd);
}
