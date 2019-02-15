/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:56:36 by nkirkby           #+#    #+#             */
/*   Updated: 2019/02/14 12:30:35 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* This file is autogenerated.
* Edit the template in .scripts/generate_libft_header.py
*/

#include <string.h>

#ifndef LIBFT_H
# define LIBFT_H

#define IS_LOWERCASE(X) ((X >= 'a') && (X <= 'z'))
#define IS_UPPERCASE(X) ((X >= 'A') && (X <= 'Z'))
#define IS_ALPHA(X) (IS_LOWERCASE(X) || IS_UPPERCASE(X))
#define IS_DIGIT(X) ((X >= '0') && (X <= '9'))

int		ft_atoi_ptr(char *str, long *out);
void	ft_putchar(char c);
void	ft_puts(char *str);
int		ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void *		ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *		ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void *		ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *		ft_memmove(void *dst, const void *src, size_t len);
void *		ft_memset(void *b, int c, size_t len);
char *		ft_strcat(char *restrict s1, const char *restrict s2);
char *		ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char *		ft_stpcpy(char * dst, const char * src);
char *		ft_strdup(const char *s1);
size_t		ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
size_t		ft_strlen(const char *s);
char *		ft_strcat(char *restrict s1, const char *restrict s2);
int		ft_strcmp(const char *s1, const char *s2);
char *		ft_stpcpy(char * dst, const char * src);
char *		ft_strstr(const char *haystack, const char *needle);
char *		ft_strchr(const char *s, int c);
char *		ft_strstr(const char *haystack, const char *needle);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
