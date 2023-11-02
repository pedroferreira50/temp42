#include "libft.h"

static int	countwords(const char *str, char c)
{
	int	i;
	int	count;
	int	check;

	check = 1;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (check == 1)
			{
				count++;
				check = 0;
			}
		}
		else
			check = 1;
		i++;
	}
	return (count);
}
/*
static int	countwords(const char *str, const char c)
{
	int	i;
	int	is_word;

	i = 0;
	if (ft_isprint(c))
	{
		is_word = 0;
		while (*str)
		{
			if ((*str == c) == is_word)
			{
				is_word = 1 - is_word;
				if (is_word)
					i++;
			}
			str++;
		}
	}
	else
		i = 1;
	return (i);
}
*/
static char **free_on_error(char **tab, unsigned int i)
{
    while (i > 0)
    {
		i--;
        free(tab[i]);
    }
    free(tab);
    return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**splitstr;

	i = 0;
	k = 0;
	//splitstr = calloc((countwords((char *)s, c)), sizeof(char *));
	splitstr = ft_calloc(countwords(s, c) + 1, sizeof(char *));
	if (!splitstr)
		return (NULL);
	splitstr[countwords(s, c)] = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c)
				j++;
			splitstr[k] = calloc(sizeof(char) * ((j - i) + 1), sizeof(char));
			if (!splitstr[k])
				return (free_on_error(splitstr, k));
			j = 0;
			while (s[i] != c)
				splitstr[k][j++] = s[i++];
			k++;
		}
		i++;
	}
	return (splitstr);
}
/*
int	main(void)
{
	char	**array;
	int	num;

	array = ft_split("                  olol", ' ');
	num = 0;
	while (array[num] != NULL) 
    	num++;
	for (int i = 0; i < num; i++) {
        printf("%s\n", array[i]);
    }
	free_on_error(array, num +1);
	return (0);
}
*/
/*
int main(void)
{
	printf("%d", countwords("hello!", 32:' '));
}*/