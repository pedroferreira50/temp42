/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:57:58 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/11 11:35:42 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_glist
{
	int				startc;
	int				endc;
	char			string[BUFFER_SIZE];
	struct s_glist	*next;
}				t_glist;

typedef struct s_gvar
{
	size_t	bytes_read;
	size_t	nb_nodes;
	int		eoleof;
}				t_gvar;

void	free_all_list(t_glist *node);
char	*stash_to_out(t_glist **ptr, size_t nb_nodes, int eoleof);
int		stopcar_in_node(t_glist *node, t_gvar *var);
t_glist	*create_node(size_t *nb);
t_glist	*fill_nodes(t_glist **sptr, int fd, t_gvar *var);
char	*get_next_line(int fd);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t size);
void	ft_bzero(void *s, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_putchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
void	ft_putnbr(unsigned int p, int *ptrlen);
int		ft_printptr(unsigned long long ptr);
int		ft_print_uint(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
void	ft_put_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned int num);

#endif
