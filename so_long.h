/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:35:45 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/20 18:35:45 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 20

# include <unistd.h>
# include "./mlx_linux/mlx.h" 
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		closed;
	int		color;
	t_data	*img;
}	t_vars;

typedef struct s_map_values
{
	int	player;
	int collectable;
	int exit;
	int height;
	int length;
	int	walls;
	char	*first_line;
	char	*last_line;
} t_map_values;

int 	get_map(int fd);
char 	*get_next_line(int fd);
char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
void	check_elements(t_map_values *valid, char *str);
int 	check_valid(t_map_values map);
int 	str_size(const char *s);

#endif