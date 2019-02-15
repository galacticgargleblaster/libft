/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/14 18:24:36 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
	size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((char*)src)[i] == c)
			return (void *)(src + i + 1);
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (NULL);
}
