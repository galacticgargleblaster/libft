/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:59:03 by student           #+#    #+#             */
/*   Updated: 2019/05/11 22:17:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endswith(const char *s, const char c)
{
	size_t	idx;

	if (s && (idx = ft_strlen(s)) && s[idx - 1] == c)
		return 1;
	return 0;
}
