#include "hush-02.h"

int	verificar_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{	
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int base_e_valida(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!(base) || !(*base) || !*(base + 1))
		return (0);
	while (base[i])
	{
		if ((base[i] == '+' || base[i] == '-') || (base[i] < 32 || base[i] > 126))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	validar_entrada(char *input)
{
	while (*input)
	{
		if (*input < '0' || *input > '9')
			return (0);
		input++;
	}
	return (1);
}
