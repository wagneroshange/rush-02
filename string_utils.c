#include "hush-02.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr_dest;

	ptr_dest = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ptr_dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && (*s1 == *S2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
