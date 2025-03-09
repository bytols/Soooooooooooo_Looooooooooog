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
LIBFT = libft.a

# Caminho para MiniLibX
MINILIB_PATH = ./mlx_linux/
MINILIB_A = $(MINILIB_PATH)libmlx.a
LIBFT_PATH = ./libft/
LIBFT_A = ./libft/libft.a

# Flags de compilação
FLAGS = -Wall -Werror -Wextra -Imlx_linux -O3

# Compilador e criador de biblioteca estática
CC = cc
AR = ar rcs

# Arquivos fonte e objetos
SRC = open_window.c so_long.c get_map.c get_next_line.c flood_fill.c so_long_str_utils.c game.c
OBJ = $(SRC:.c=.o)

# Bibliotecas externas
LIBX = -L$(MINILIB_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Regra para compilar arquivos .c para .o
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(MINILIB_A) $(LIBFT_A)  $(LIB_NAME) $(NAME) 

# Compilar MiniLibX se necessário
$(MINILIB_A):
	make -C $(MINILIB_PATH)

# Criar a biblioteca estática
$(LIB_NAME): $(OBJ)
	$(AR) $(LIB_NAME) $(OBJ)

# Criar o executável final usando a biblioteca
$(NAME): $(LIB_NAME)
	$(CC) so_long.o $(LIB_NAME) $(LIBFT_A) $(LIBX) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_PATH)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB_NAME) $(NAME)
	rm -rf $(OBJ_SOURCE)
	rm -rf $(OBJ)
	rm -rf $(LIBFT_A)
	rm -rf $(MINILIB_A)

.PHONY: all clean fclean re
