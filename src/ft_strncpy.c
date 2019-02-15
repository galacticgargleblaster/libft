/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/15 11:10:15 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && (i < n))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
