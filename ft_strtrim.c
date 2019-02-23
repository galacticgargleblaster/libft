/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/22 12:27:37 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string given as
** argument without whitespaces at the beginning or at the end of the string.
** Will be considered as whitespaces the following characters ’ ’, ’\n’ and
** ’\t’. If s has no whitespaces at the beginning or at the end, the function
** returns a copy of s. If the allocation fails the function returns NULL.
**
** Param. #1 The string to be trimed.
** Return value The “fresh” trimmed string or a copy of s.
*/

#define IS_WHITESPACE(X) (X == ' ' || X == '\n' || X == '\t')

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start_idx;
	size_t	len;
	char	*fresh;

	start_idx = 0;
	while (s[start_idx] && IS_WHITESPACE(s[start_idx]))
		start_idx++;
	len = 0;
	if (s[start_idx])
	{
		while (s[start_idx + len])
			len++;
		len--;
		while (len && IS_WHITESPACE(s[start_idx + len]))
			len--;
		len++;
	}
	fresh = ft_strnew(len);
	if (fresh)
		fresh = ft_strncpy(fresh, &s[start_idx], len);
	return (fresh);
}
