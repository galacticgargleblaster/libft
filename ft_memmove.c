/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/15 09:42:23 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*buf;
	size_t	i;

	buf = malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		buf[i] = ((char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = buf[i];
		i++;
	}
	free(buf);
	return (dst);
}
