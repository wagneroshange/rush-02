#ifndef RUSH-02
#define RUSH-02

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 4096
#define MAX_ENTRADAS 1000
typedef struct	s_dicionario
{
	char	*chave;
	char	*valor;
}	t_dic;
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
unsigned int	ft_strlen(char *str);
int base_e_valida(char *base);
int	verificar_base(char c, char *base);
int ler_arquivo(char *caminho_do_arquivo, char **ctd_dicio);
t_dic	*analisar_dicionario(char *caminho_do_arquivo, int *num_entradas);
char	*buscar_no_dicionario(t_dic *dicio, int num_entradas, char* chave);
char	*extrair_chave(char *linha, int *tamanho_da_chave);
char	*extrair_valor(char *linha, int tamanho_do_valor);
t_dic	*processar_linha(char *linha, int *num_entradas, t_dic *dicio);
int processar_ctd_dicio(char *ctd_dicio, int bytes_lidos, t_dic *dicio, int *num_entradas);
void	liberar_dicionario(t_dic *dicio, int num_entradas);
int	validar_entrada(char *input);
char	*converter_numero(char *num_str, t_dic *dicio, int num_entradas);
#endif
