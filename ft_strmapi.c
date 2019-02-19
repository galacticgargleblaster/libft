/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 20:39:25 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed as argument by
** giving its index as first argument to create a “fresh” new string
** (with malloc(3)) resulting from the successive applications of f.
**
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s and its index.
** Return value The “fresh” string created from the successive applications of
** f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	char	*fresh;
	size_t	len;
	size_t	idx;

	len = ft_strlen(s);
	fresh = ft_strnew(len);
	if (fresh)
	{
		idx = 0;
		while(idx < len)
		{
			fresh[idx] = f(idx, s[idx]);
			idx++;
		}
	}
	return fresh;

}
