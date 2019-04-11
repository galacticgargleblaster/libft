/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xxd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:59:03 by student           #+#    #+#             */
/*   Updated: 2019/04/10 22:01:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#define TO_HEX_ASCII(c) ((c) < 10 ? ((c) + '0') : ((c) - 10 + 'a'))
#define IS_PRINTABLE(c) (((c) >= ' ') && ((c) <= '~'))

static void	print_hex(const void *addr, size_t size)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			c = (void *)addr + i;
			ft_putchar(TO_HEX_ASCII((*c) / 16));
			ft_putchar(TO_HEX_ASCII((*c) % 16));
		}
		else
			ft_putstr("  ");
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
}

static void	print_ascii(const void *addr, size_t size)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	while (i < size)
	{
		c = (void *)addr + i;
		if (IS_PRINTABLE(*c))
			ft_putchar(*c);
		else
			ft_putchar('.');
		i++;
	}
}

void		ft_xxd(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		print_hex(addr + i, MIN(16, size - i));
		print_ascii(addr + i, MIN(16, size - i));
		ft_putchar('\n');
		i += 16;
	}
}
