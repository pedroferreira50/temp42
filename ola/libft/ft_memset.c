#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}