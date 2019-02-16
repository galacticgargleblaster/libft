/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/15 09:58:09 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *ptr;

	ptr = s1;
	while (*ptr)
		ptr++;
	while ((*ptr = *s2))
	{
		ptr++;
		s2++;
	}
	return (s1);
}
