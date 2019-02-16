/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:01:14 by nkirkby           #+#    #+#             */
/*   Updated: 2018/10/02 04:02:16 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** if malloc() fails, it will set errno to ENOMEM and return a NULL pointer.
*/

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i])
	{
		i++;
	}
	copy = malloc(sizeof(*src) * i + 1);
	if (copy)
	{
		i = 0;
		while (src[i])
		{
			copy[i] = src[i];
			i++;
		}
	}
	return (copy);
}
