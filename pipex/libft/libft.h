/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:03:39 by cprojean          #+#    #+#             */
/*   Updated: 2023/05/29 11:43:48 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				pos;
	struct s_stack	*next;
}					t_stack;
//Part one
/////////////////

//ft_strlen
size_t	ft_strlen(const char *s);

//ft_calloc
void	*ft_calloc(size_t count, size_t size);

//ft_atoi
int		ft_atoi(const char *str);

//ft_isalnum
int		ft_isalnum(int c);

//ft_isalpha
int		ft_isalpha(int c);

//ft_isascii
int		ft_isascii(int c);

//ft_isdigit
int		ft_isdigit(int c);

//ft_isprint
int		ft_isprint(int c);

//ft_strchr
char	*ft_strchr(const char *s, int c);

//ft_strlcat
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

//ft_strlcpy
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//ft_strncmp
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//ft_strnstr
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

//ft_strrchr
char	*ft_strrchr(const char *s, int c);

//ft_tolower
int		ft_tolower(int c);

//ft_toupper
int		ft_toupper(int c);

//ft_bzero
void	ft_bzero(void *s, size_t n);

//ft_memset
void	*ft_memset(void *b, int c, size_t len);

//ft_memchr
void	*ft_memchr(const void *s, int c, size_t n);

//ft_memcmp
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//ft_memcpy
void	*ft_memcpy(void *dst, const void *src, size_t n);

//ft_memmove
void	*ft_memmove(void *dst, const void *src, size_t len);

//ft_strdup
char	*ft_strdup(const char *s1);

//Part two
//////////////////

//ft_substr
char	*ft_substr(char const *s, unsigned int start, size_t len);

//ft_strjoin
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin2(char *s1, char *s2);

//ft_strtrim
char	*ft_strtrim(char const *s1, char const *set);

//ft_itoa
char	*ft_itoa(int n);

//ft_strmapi
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

//ft_striteri
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//ft_split
char	**ft_split(char *str, char c);

//File descriptors
//////////////////

//ft_putchar_fd
void	ft_putchar_fd(char c, int fd);

//ft_putstr_fd
void	ft_putstr_fd(char *s, int fd);

//ft_putendl_fd
void	ft_putendl_fd(char *s, int fd);

//ft_putnbr_fd
void	ft_putnbr_fd(int n, int fd);

//Partie Bonus
//////////////////

//ft_lstnew
t_stack	*ft_lstnew(int data);

//ft_lstadd_front
void	ft_lstadd_front(t_stack **lst, t_stack *new);

//ft_lstsize
int		ft_lstsize(t_stack *lst);

//ft_lstlast
t_stack	*ft_lstlast(t_stack *lst);

//ft_lstadd_back
void	ft_lstadd_back(t_stack **lst, t_stack *new);

//ft_lstdelone
void	ft_lstdelone(t_stack *lst, void (*del)(int));

//ft_lstclear
void	ft_lstclear(t_stack **lst);
void	ft_lstintclear(t_stack **lst);

//ft_lstiter
void	ft_lstiter(t_stack *lst, void (*f)(int));

//ft_lstmap
t_stack	*ft_lstmap(t_stack *lst, int (*f)(int));

//PRINTF
//////////////////

int		ft_printf(const char *array, ...);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int x, int *count);
void	ft_putlnbr(unsigned int x, int *count);
void	ft_convert_hexa_maj(unsigned int number, int *count);
void	ft_convert_hexa_min(unsigned int number, int *count);
void	ft_print_address(size_t number, int *count);
void	which_varia(const char *array, va_list variadic, size_t *i, int *count);

#endif
