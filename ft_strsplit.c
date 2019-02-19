/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 20:41:25 by nkirkby          ###   ########.fr       */
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

struct	substring_s
{
		char	*start;
		size_t	len;
};

char	**ft_strsplit(char const *s, char c)
{
	char	**fresh_array;
	char	*substring_end;
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		substring_end = ft_strchr(&s[idx], c);

		idx++;
	}	
	ft_strchr(s, c);
	fresh_array = 0;
	return fresh_array;
}

/*
** 	Does this need two iterations over the string?
**	Yes -- Need to know how many substrings there are before malloc'ing the array
**	This will be easier to implement with some list types...
*/