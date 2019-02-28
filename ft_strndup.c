/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:01:14 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/28 15:40:02 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*copy;

	copy = ft_strnew(n);
	if (copy)
	{
		i = 0;
		while (s1[i] && i < n)
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = 0;
	}
	return (copy);
}
