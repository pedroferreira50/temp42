#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[len] = '\0';
	return (str);
}