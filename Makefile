# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 11:25:47 by erocha-l          #+#    #+#              #
#    Updated: 2025/02/01 00:31:29 by erocha-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  so_long.a

FLAGS =-Wall	\
       -Werror  \
       -Wextra  \

CC= cc

C_SOURCE= open_window.c

H_FILES = so_long.h 

LibX = -Lmlx_linux -lmlx_Linux ./mlx_linux/libmlx.a -Imlx_linux -lXext -lX11 -lm -lz

OBJ_SOURCE= open_window.c.o

.c.o:
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SOURCE)
	ar -src  $(NAME) $(OBJ_SOURCE)

$(OBJ_SOURCE): $(C_SOURCE)
	$(CC) $(FLAGS) -c $(C_SOURCE)
 
re: $(NAME) $(OBJ_SOURCE)
	make fclean
	make all

clean:
	rm -rf $(OBJ_SOURCE)

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJ_SOURCE)

.PHONY: all clean fclean re
