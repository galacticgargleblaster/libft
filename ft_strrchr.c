/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/18 01:25:11 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;
	char *last_occurence;

	last_occurence = NULL;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			last_occurence = ptr;
		ptr++;
	}
	if (*ptr == 0 && c == 0)
		return (ptr);
	return (last_occurence);
}
