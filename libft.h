/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:56:36 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/13 21:55:35 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#ifndef LIBFT_H
# define LIBFT_H

int		ft_atoi(char *str);
int		ft_atoi_ptr(char *str, long *out);
void	ft_swap(int *a, int *b);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_itoa(long n);
char	*ft_strdup(char *src);
char	**ft_split_whitespaces(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);


#endif
