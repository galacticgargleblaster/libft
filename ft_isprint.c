/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/14 17:46:39 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_isprint(int c)
{
	return ((c >= ' ' && c <= '\'') || (c >= '(' && c <= '\\')
			|| IS_DIGIT(c) || (c >= ':' && c <= '?') || (c == '@')
			|| IS_UPPERCASE(c) || (c >= '[' && c <= '_') || (c == '`')
			|| IS_LOWERCASE(c) || (c >= '{' && c <= '~'));
}