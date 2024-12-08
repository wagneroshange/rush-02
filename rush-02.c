#include "rush-02.h"

void	print_result(char *resultado)
{
		if (resultado == NULL)
		{
			write(1, "Dict Error\n", 11);
		}
		else
		{
			write(1, result, ft_strlen(result));
			write(1, "\n", 1);
		}
}

int	main(int argc, char *argv[])
{
	t_dic *dicionario;
	int	num_entradas;
	char	*resultado;
	char	*caminho_do_arquivo;
	char	str_entrada;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (argc == 3)
	{
		caminho_do_arquivo = argv[1];
	}
	else
	{
		caminho_do_arquivo = "numbers.dict"
	}
	dicionario = analisar_dicionario(caminho_do_arquivo, &num_entradas);
	if (dicionario == NULL)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (argc == 3)
	{
		str_entrada = argv[2];
	}
	else
	{
		str_entrada = argv[1];
	}
	if (!validar_entrada(str_entrada))
	{
		write(1, "Error\n", 6);
		liberar_dicionario(dicionario, num_entradas);
		return (1);
	}
	resultado = converter_numero(entrada_str, dicionario, num_entradas); //essa é a função que faltapraticamente (função converter_numero) é a função que faz o objctivo do programa converter um número de comprensão para extenso
	print_result(resultado);
	free(resultado);
	liberar_dicionario(dicionario, num_entradas);
	return (0);
}
