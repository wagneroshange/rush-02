NAME = rush-02

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = rush-02.c conversao.c dicionario_utils.c string_utils.c validacao.c

OBJ = $(SRC:.c=.o) # Substitui .c por .o nos nomes dos arquivos de origem

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c rush-02.h # Regra genérica para compilar arquivos .c em .o
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
