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

typedef struct s_map_values_fd
{
	int	player;
	int collectable;
	int exit;
} t_map_values_fd;

int 	get_map(int fd, char *map_path);
char 	*get_next_line(int fd);
char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
void	check_elements(t_map_values *valid, char *str);
int 	check_valid(t_map_values map);
int 	str_size(const char *s);
void	free_matrix(char *** matrix);
char 	**create_map_matrix(int fd, int size, int height);
void	dfs(char **grid, int j, int i, t_map_values_fd *map);
int		flood_fill(int size, int height, char *map_path, t_map_values map_full);
void	find_player_position(char **matrix, int *i, int *j, int height);
int		matrix_height(char **grid);
void init_struct(t_map_values * valid);


#endif