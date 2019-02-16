/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/15 11:02:48 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
			size_t dstsize)
{
	size_t	dst_idx;
	size_t	src_idx;

	if (dstsize == 0)
		return (0);
	dst_idx = 0;
	while (dst[dst_idx])
		dst_idx++;
	src_idx = 0;
	while (dst_idx < dstsize)
		dst[dst_idx++] = src[src_idx++];
	return (dst_idx);
}
