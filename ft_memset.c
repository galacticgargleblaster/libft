/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:12:41 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/13 19:27:51 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char *str;

	str = b;
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}

	return (b);
}
