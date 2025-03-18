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
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		ww;
	int		wh;
	char	**grid;
	int		x;
	int		y;
	int		lx;
	int		ly;
	int		collectable_max;
	int		collectable;
	int		move;
	void	*spr_g;
	void	*spr_c;
	void	*spr_p;
	void	*spr_r;
	void	*spr_e;
	void	*spr_pe;
}	t_vars;

typedef struct s_map_values
{
	int		player;
	int		collectable;
	int		exit;
	int		height;
	int		length;
	int		walls;
	char	*first_line;
	char	*last_line;
}	t_map_values;

typedef struct s_map_values_fd
{
	int	player;
	int	collectable;
	int	exit;
}	t_map_values_fd;

int		get_map(int fd, int size, char *map_path);
char	*get_next_line(int fd);
char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
void	check_elements(t_map_values *valid, char *str);
int		check_valid(t_map_values *map);
int		str_size(const char *s);
void	free_matrix(char ***matrix);
char	**create_map_matrix(int fd, int size, int height);
void	dfs(char **grid, int j, int i, t_map_values_fd *map);
int		flood_fill(int size, int height, char *map_path, t_map_values map_full);
void	find_player_position(char **matrix, int *i, int *j, int height);
int		matrix_height(char **grid);
void	init_struct(t_map_values *valid, char *line);
void	free_matrix(char ***matrix);
void	game(char *map, int fd);
void	render_map(char *map_name, t_vars *window);
void	render_line(char *line, t_vars **win, int i);
void	gameplay(char *map, t_vars *vars, int size, int height);
int		movement(int keycode, t_vars *vars);
void	update(t_vars **vars, int x, int y);
char	check_position(t_vars **t_vars, int x, int y);
int		count_collectable(char **grid);
int		x_press( t_vars *vars);
void	init_img(t_vars **w);
void	free_img(t_vars *w);
void	free_partial_matrix(char ***matrix, int last);
void	free_and_exit(t_vars **vars);
void	collectable(t_vars **v);
void	error_and_exit(char *str, int size);
int		check_file_name(char *s);
int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *c, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putb(unsigned int n, int fd, char *base, int *count);
void	convert_ptr(void *ptr, int *count);
void	ft_putunbr_fd(unsigned int n, int fd, int *count);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);


#endif