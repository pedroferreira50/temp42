#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	size_t			n_buffer;
	unsigned char	buffer[n];

	i = 0;
	n_buffer = n;
	if (!dest && !src)
		return (0);
	while (n_buffer-- > 0)
	{
		buffer[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (n-- > 0)
	{
		((unsigned char *)dest)[i] = buffer[i];
		i++;
	}
	return (dest);
}
