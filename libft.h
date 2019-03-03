/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:31:08 by nkirkby           #+#    #+#             */
/*   Updated: 2019/03/02 22:49:34 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define IS_LOWERCASE(X) ((X >= 'a') && (X <= 'z'))
# define IS_UPPERCASE(X) ((X >= 'A') && (X <= 'Z'))
# define IS_ALPHA(X) (IS_LOWERCASE(X) || IS_UPPERCASE(X))
# define IS_DIGIT(X) ((X >= '0') && (X <= '9'))
# define MAX(X, Y) ((X) > (Y) ? X : Y)
# define MIN(X, Y) ((X) > (Y) ? Y : X)

/*
** content :
** The data contained in the link. The void * allows to store any kind of data.
**
** content_size :
** The size of the data stored. The void * type doesn’t allow you to know the
** size of the pointed data, as a consequence, it is necessary to save its size.
** For instance, the size of the string "42" is 3 bytes and the 32bits integer
** 42 has a size of 4 bytes.
**
** next : The next link’s address or NULL if it’s the last link.
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**	MEMORY MANIPULATION FUNCTIONS
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
**	STRING MANIPULATION FUNCTIONS
*/

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *s1, size_t n);
size_t				ft_strlcat(char *restrict s1, const char *restrict s2,
								size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);

/*
** PRINTING FUNCTIONS
*/

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);

/*
**	SINGLY LINKED LIST FUNCTIONS
*/

t_list				*ft_lstnewlink_copy(void const *content,
								size_t content_size);
t_list				*ft_lstnewlink(void const *content);
void				ft_lstdelone(t_list **alst, void (*del)(void*));
void				ft_lstdel(t_list **alst, void (*del)(void *));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstlen(t_list **lst);
t_list				*ft_lstpush(t_list *lst, void const *content);
void				*ft_lstpop(t_list **list_head);
void				*ft_lstnext(t_list *lst, int (f)(t_list *elem));
void				*ft_lstremove(t_list **alst, void *content);
/*
**  lstcpy is unuseful, consider making a lstalias to copy just the
**	t_lst structs, or a lstdeepcpy(t_list *lst, void*(*cpy_content)(void *))
**  to copy list and content.
*/

#endif
