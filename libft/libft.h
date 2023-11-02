#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

size_t	ft_strlen(const char *str);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif