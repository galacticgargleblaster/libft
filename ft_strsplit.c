/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/21 14:10:14 by nkirkby          ###   ########.fr       */
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

static		t_list **find_substrings(char const *s, char c)
{
	t_list	**substrings;
	char	*substring;
	size_t	idx;
	size_t	len;

	idx = 0;
	len = 0;
	substrings = NULL;
	while (s[idx])
	{
		if (s[idx] == c)
		{
			if (len)
			{
				substring = ft_strnew(len);
				ft_strncpy(substring, &s[idx], len);
				ft_lstadd(substrings, ft_lstnew(substring, len + 1));
			}
			len = 0;
		}
		else
			len++;
		idx++;
	}
	return (substrings);
}

char	**ft_strsplit(char const *s, char c)
{
	char			**fresh_array;
	size_t			idx;
	size_t			wc;

	idx = 0;
	wc = 0;
	while (s[idx])
	{
		if (s[idx] != c && idx > 0 && s[idx - 1] == c)
		idx++;
		idx++;
	}
	find_substrings(s, c);
	fresh_array =  0;
	return fresh_array;
}