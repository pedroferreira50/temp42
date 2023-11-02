#include "libft.h"
#include <string.h>
/*
char	*ft_itoa(int n)
{
	int	i;
	int	size;
	char	*str;

	i = 0;
	size = n;
	while (size != 0)
	{
		size = size / 10;
		i++;
	}
	if (n == 0)
	{
		str = malloc(2);
		return (str = "0");
	}
	if (n == -2147483648)
	{
		str = malloc(12);
		return (str = "-2147483648");
	}
	else if (n > 0)
	{
		str = malloc(i + 2);
		str[0] = '-';
	}
	else
		str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	while (n != 0)
	{
		str[--i] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
*/
/*
char *add_char(char *str, char c) {
    size_t len = str ? strlen(str) : 0;

    str[len] = c;
    str[len + 1] = '\0';

    return str;
}
char	*ft_itoatwo(char *str, int n)
{
	if (n == -2147483648)
	{
		str = add_char(str, '-');
		str = add_char(str, '2');
		ft_itoatwo(str, 147483648);
	}
	else if (n < 0)
	{
		str = add_char(str, '-');
		n = -n;
		ft_itoatwo(str, n);
	}
	else if (n > 9)
	{
		ft_itoatwo(str, n / 10);
		ft_itoatwo(str, n % 10);
	}
	else
		str = add_char(str, n + '0');
	return (str);
}
char	*ft_itoa(int n)
{
	char	*str;
	int	size;
	int	i;

	size = n;
	i = 0;

	while (size != 0)
	{
		size = size / 10;
		i++;
	}
	if (n < 0)
		str = malloc(i + 2);
	else if (n > 0)
		str = malloc(i + 2);
	else if ( n == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (ft_itoatwo(str, n));
}

int	main(void)
{
	int	a = 9;
	char *str = ft_itoa(a);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
#include <stdlib.h>

char *add_char(char *str, char c) {
    size_t len = str ? strlen(str) : 0;
    char *new_str = (char *)malloc(len + 2); // Allocate memory for the new string.

    if (new_str == NULL) {
        // Handle memory allocation failure.
        return NULL;
    }

    if (str) {
        strcpy(new_str, str); // Copy the existing string into the new one.
        free(str); // Free the old string.
    }

    new_str[len] = c;
    new_str[len + 1] = '\0';

    return new_str;
}

char *ft_itoatwo(char *str, int n) {
    if (n == -2147483648) {
        str = add_char(str, '-');
        str = add_char(str, '2');
        return ft_itoatwo(str, 147483648); // Return the result of the recursive call.
    } else if (n < 0) {
        str = add_char(str, '-');
        n = -n;
        return ft_itoatwo(str, n);
    } else if (n > 9) {
        str = ft_itoatwo(str, n / 10); // Recursively build the string.
        return ft_itoatwo(str, n % 10);
    } else {
        return add_char(str, n + '0');
    }
}

char *ft_itoa(int n) {
    if (n == 0) {
        char *str = (char *)malloc(2);
        if (str == NULL) {
            // Handle memory allocation failure.
            return NULL;
        }
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    int size = n;
    int i = 0;

    while (size != 0) {
        size = size / 10;
        i++;
    }

    char *str;
    if (n < 0) {
        str = (char *)malloc(i + 2);
    } else {
        str = (char *)malloc(i + 1);
    }

    if (str == NULL) {
        // Handle memory allocation failure.
        return NULL;
    }

    return ft_itoatwo(str, n);
}

int	main(void)
{
	int	a = 1284681320;
	char *str = ft_itoa(a);
	printf("%s\n", str);
	free(str);
	return (0);
}