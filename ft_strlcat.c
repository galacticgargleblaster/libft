/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 13:05:50 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *src, size_t dstsize)
{
	size_t	dst_idx;
	size_t	src_idx;
	size_t	total_length;

	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	total_length = ft_strlen(dst) + ft_strlen(src);
	dst_idx = ft_strlen(dst);
	src_idx = 0;
	while ((dst_idx + 1) < dstsize)
	{
		dst[dst_idx++] = src[src_idx++];
	}
	return (total_length);
}
