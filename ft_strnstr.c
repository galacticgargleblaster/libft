/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 13:27:28 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	max;

	idx = 0;
	if ((ft_strlen(haystack) < ft_strlen(needle)) || (len < ft_strlen(needle)))
		return (NULL);
	max = MIN(ft_strlen(haystack) - ft_strlen(needle), len - ft_strlen(needle));
	while (idx <= max)
	{
		if (ft_strncmp(needle, (haystack + idx), ft_strlen(needle)) == 0)
			return ((char*)(haystack + idx));
		idx++;
	}
	return (NULL);
}
