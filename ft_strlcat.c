/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/17 23:48:58 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *src, size_t dstsize)
{
	size_t	dst_idx;
	size_t	src_idx;
	size_t	total_length;

	total_length = ft_strlen(dst) + ft_strlen(src);
	dst_idx = 0;
	while (dst[dst_idx])
		dst_idx++;
	src_idx = 0;
	while ((dst_idx + 1) < dstsize)
	{
		dst[dst_idx++] = src[src_idx++];
	}
	dst[dst_idx] = 0;
	return (total_length);
}
