#include "rush-02.h"

void	liberar_dicionario(t_dic *dicio, int num_entradas)
{
	int	i;

	i = 0;
	while (i < num_entradas)
	{
		free(dicio[i].chave);
		free(dicio[i].valor);
		i++;
	}
	free(dicio);
}

char *extrair_chave(char *linha, int *tam_chave)
{
	int		i;
	char	*chave;

	i = 0;
	while (linha[i] != ':' && line[i] != '\0')
		i++;
	if (linha[i] == '\0')
			return (0);
	*tam_chave = i;
	chave = (char *)malloc(sizeof(char) * (i + 1));
	if (!chave)
		return (0);
	strncpy(chave, linha, i);
	chave[i] = '\0';
	return (chave);
}

char *extrair_valor(char *linha, int tam_chave){
	int		i;
	int		inicio;
	char	*valor;

	i = tam_chave + 1;
	while (linha[i] == ' ' || linha[i] == '\t')
		i++;
	inicio = i;
	while (linha[i] != '\n' && linha[i] != '\0')
		i++;
	valor = (char *)malloc(sizeof(char) * (i - inicio + 1));
	if (!valor)
		return (NULL);
	strncpy(valor, linha + inicio, i - inicio);
	valor[i - inicio] = '\0';
	return (valor);
}

t_dict *processar_linha(char *linha, int *num_entradas, t_dic *dicio)
{
	int		tam_chave;
	char	*chave; 
	char	*valor;

	chave = extrair_chave(linha, &_tam_chave);
	if (!chave)
		return (0);
	valor = extrair_valor(linha, tam_valor);
	if (!valor)
	{
		free(chave);
		return (0);
	}
	dicio[*num_entradas].chave = chave;
	dicio[*num_entradas].valor = valor;
	(*num_entradas)++;
	return (dicio);
}

int	ler_arquivo(char *caminho_do_arquivo, char **ctd_dicio) 
{
	char	buffer[BUFFER_SIZE + 1];
	int		fd;
	int		bytes_lidos;

    fd = open(caminho_do_arquivo, O_RDONLY);
    if (fd == -1)
		return (0);
    bytes_lidos = read(fd, buffer, BUFFER_SIZE);
    if (bytes_lidos == -1)
	{
		close(fd);
		return (0);
	}
	if (bytes_lidos == 0)
		return (-1);
    buffer[bytes_lidos] = '\0';
    *ctd_dicio = (char *)malloc(sizeof(char) * (bytes_lidos + 1));
    if (!*ctd_dicio)
	{
		close(fd);
		return (0);
	}
    ft_strcpy(*ctd_dicio, buffer);
	close(fd);
	return (bytes_lidos);
}

int	processar_ctd_dicio(char *ctd_dicio, int bytes_lidos, t_dic *dicio, int *num_entradas)
{
	int i;
	
	i = 0;
	while (i < bytes_lidos && *num_entradas < MAX_ENTRADAS)
	{
		if (!(processar_linha(ctd_dicio, num_entradas, dicio)))
			return (0);
		while (ctd_dicio[i] != '\n' && ctd_dicio[i] != '\0') 
			i++;
		if (ctd_dicio[i] == '\n') 
			i++;
    }
    return (1);
}

t_dic	*analisar_dicionario(char *caminho_do_arquivo, int *num_entradas)
{
	char *ctd_dicio;
	int	bytes_lidos;
	t_dic	*dicio;

	bytes_lidos = ler_arquivo(caminho_do_arquivo, &ctd_dicio);
	if (!bytes_lidos)
		return (0);
	dicio = (t_dic *)malloc(sizeof(t_dic) * MAX_ENTRADAS);
	if (!dicio)
	{
		free(ctd_dicio);
		return (0);
	}
	if (!processar_ctd_dicio(ctd_dicio, bytes_lidos, dicio, num_entradas))
	{
		free(dicio);
		free(ctd_dicio);
		return (0);
	}
	free(ctd_dicio);
	return (dicio);
}

char	*buscar_no_dicionario(t_dic *dicio, int num_entradas, char* chave)
{
	int	i;
	int	result;

	i = 0;
	while (i < num_entries)
	{
		if(ft_strcmp(dictionary[i].key, key) == 0)
				return (dictionary[i].value);
		i++;
	}
	return (NULL);
}
