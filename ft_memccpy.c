/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/17 18:03:24 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_c;
	unsigned char	*dst_c;

	src_c = (unsigned char *)src;
	dst_c = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		if (src_c[i] == (unsigned char)c)
			return (void *)(dst_c + i + 1);
		i++;
	}
	return (NULL);
}
