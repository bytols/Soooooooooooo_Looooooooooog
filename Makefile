# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 11:25:47 by erocha-l          #+#    #+#              #
#    Updated: 2025/02/17 17:06:43 by erocha-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome da biblioteca e do executável final
NAME = so_long
LIB_NAME = libso_long.a  # Biblioteca estática

# Caminho para MiniLibX
MINILIB_PATH = ./mlx_linux/
MINILIB_A = $(MINILIB_PATH)libmlx_Linux.a

# Flags de compilação
FLAGS = -Wall -Werror -Wextra -Imlx_linux -O3

# Compilador e criador de biblioteca estática
CC = cc
AR = ar rcs

# Arquivos fonte e objetos
SRC = open_window.c
OBJ = $(SRC:.c=.o)

# Bibliotecas externas
LIBX = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Regra para compilar arquivos .c para .o
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(MINILIB_A) $(LIB_NAME) $(NAME)

# Compilar MiniLibX se necessário
$(MINILIB_A):
	make -C $(MINILIB_PATH)

# Criar a biblioteca estática
$(LIB_NAME): $(OBJ)
	$(AR) $(LIB_NAME) $(OBJ)

# Criar o executável final usando a biblioteca
$(NAME): $(LIB_NAME)
	$(CC) $(OBJ) $(LIB_NAME) $(LIBX) -o $(NAME)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB_NAME) $(NAME)

.PHONY: all clean fclean re
