/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/23 13:17:17 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) obtained by spliting s using
** the character c as a delimiter. If the allocation fails the function returns
** NULL. Example:
** ft_strsplit("*hello*fellow***students*", ’*’) returns the array
** ["hello", "fellow", "students"].
**
** Param. #1 The string to split.
** Param. #2 The delimiter character.
** Return value The array of “fresh” strings result of the split.
*/

#include "libft.h"
#include <stdlib.h>

static void		push_substring(t_list **substrings,
					char const *start_addr, size_t len)
{
	char		*substring;

	substring = ft_strnew(len);
	if (substring)
	{
		ft_strncpy(substring, start_addr, len);
		*substrings = ft_lstpush(*substrings, substring, len + 1);
	}
}

static t_list	*find_substrings(char const *s, char c)
{
	t_list		*substrings;
	size_t		idx;
	size_t		len;

	idx = 0;
	len = 0;
	substrings = NULL;
	while (s[idx])
	{
		if (s[idx] == c)
		{
			if (len)
				push_substring(&substrings, &s[idx - len], len);
			len = 0;
		}
		else
			len++;
		idx++;
	}
	if (len == idx)
		push_substring(&substrings, s, len);
	return (substrings);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**fresh_array;
	size_t		len;
	t_list		*substrings;

	substrings = find_substrings(s, c);
	len = ft_lstlen(&substrings);
	fresh_array = malloc(sizeof(char*) * len);
	while (len)
		fresh_array[--len] = ft_lstpop(&substrings);
	return (fresh_array);
}
