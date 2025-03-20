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

NAME = so_long
LIB_NAME = libso_long.a 

MINILIB_PATH = ./mlx_linux/
MINILIB_A = $(MINILIB_PATH)libmlx.a

FLAGS = -Wall -Werror -Wextra -Imlx_linux -O3

CC = cc
AR = ar rcs

SRC = ft_bzero.c ft_strjoin.c ft_strchr.c ft_calloc.c ft_strdup.c ft_strlcpy.c ft_strlen.c so_long.c get_map.c get_next_line.c flood_fill.c so_long_str_utils.c game.c gameplay.c ft_putchar_fd.c ft_printf.c ft_putstr_fd.c ft_putnbr_fd.c ft_putb.c ft_putnbr_ptr_fd.c ft_putunbr_fd.c
OBJ = $(SRC:.c=.o)

LIBX = -L$(MINILIB_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(MINILIB_A) $(LIB_NAME) $(NAME) 

$(MINILIB_A):
	make -C $(MINILIB_PATH)

$(LIB_NAME): $(OBJ)
	$(AR) $(LIB_NAME) $(OBJ)

$(NAME): $(LIB_NAME)
	$(CC) so_long.o $(LIB_NAME) $(LIBX) -o $(NAME)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB_NAME) $(NAME)
	rm -rf $(OBJ_SOURCE)
	rm -rf $(OBJ)
	rm -rf $(MINILIB_A)

.PHONY: all clean fclean re
