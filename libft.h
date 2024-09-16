/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:29:19 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/08/23 13:23:11 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "get_next_line/get_next_line_bonus.h"
# include <stdarg.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list_env
{
	void				*content;
	struct s_list_env	*next;
}				t_list_env;

char		*ft_strstr(char *str, char *to_find);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strtok(char *str, const char *delim);
char		*ft_strpbrk(const char *s, const char *accept);
size_t		ft_strspn(const char *s, const char *accept);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strcpy(char *s1, char const *s2);
char		*ft_strcat(char *dest, char *src);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int i);
int			ft_tolower(int i);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(int ount, int size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(char *str);
t_list_env	*ft_lstnew(void *content);
void		ft_lstadd_front(t_list_env **lst, t_list_env *new);
int			ft_lstsize(t_list_env *lst);
t_list_env	*ft_lstlast(t_list_env *lst);
void		ft_lstadd_back(t_list_env **lst, t_list_env *new);
void		ft_lstdelone(t_list_env *lst, void (*del)(void *));
void		ft_lstclear(t_list_env **lst, void (*del)(void *));
void		ft_lstiter(t_list_env *lst, void (*f)(void *));
t_list_env	*ft_lstmap(t_list_env *lst, void *(*f)(void *),
				void (*del)(void *));
int			ft_strcmp(char *s1, char *s2);
//ft_printf
void		ft_putcharacter_length(char character, int *length);
void		ft_string(char *args, int *length);
void		ft_number(int number, int *length);
void		ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void		ft_unsigned_int(unsigned int u, int *length);
void		ft_pointer(size_t pointer, int *length);
int			ft_printf(const char *string, ...);
void		*simple_realloc(void *ptr, size_t old_size, size_t new_size);
char		*ft_strndup(const char *s, size_t n);

#endif
