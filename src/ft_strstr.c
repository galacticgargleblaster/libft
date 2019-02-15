/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/15 11:35:02 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n_idx;
	size_t	h_idx;
	char	is_match;

	h_idx = 0;
	while (haystack[h_idx])
	{
		is_match = 1;
		n_idx = 0;
		while (haystack[h_idx + n_idx] && needle[n_idx] && is_match)
		{
			if (haystack[h_idx + n_idx] != needle[n_idx])
				is_match = 0;
			n_idx++;
		}
		if (is_match && (needle[n_idx] == 0))
			return (char*)(haystack + n_idx);
		h_idx++;
	}
	return (NULL);
}
