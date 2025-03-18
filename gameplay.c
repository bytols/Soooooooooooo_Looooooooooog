/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:56:48 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/09 13:56:48 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_position(t_vars **t_vars, int x, int y)
{
	char	location;
	int		loc_x;
	int		loc_y;

	loc_x = (*t_vars)->x;
	loc_y = (*t_vars)->y;
	loc_x += x;
	loc_y += y;
	if (loc_x < 0 || loc_y < 0 || loc_x > (*t_vars)->ww || loc_y > (*t_vars)->wh
		|| (*t_vars)->grid[loc_y][loc_x] == '1')
		return ('\0');
	location = (*t_vars)->grid[loc_y][loc_x];
	(*t_vars)->x += x;
	(*t_vars)->y += y;
	return (location);
}

void	update(t_vars **v, int x, int y)
{
	char	loc_value;
	void	*img;

	(*v)->lx = (*v)->x;
	(*v)->ly = (*v)->y;
	loc_value = check_position(v, x, y);
	if (loc_value == '\0')
		return ;
	if ((*v)->grid[(*v)->ly][(*v)->lx] == 'E')
		img = (*v)->spr_e;
	else
		img = (*v)->spr_g;
	mlx_put_image_to_window((*v)->mlx, (*v)->win, img,
		((*v)->lx * 16), ((*v)->ly * 16));
	if (loc_value == 'E')
		img = (*v)->spr_pe;
	else
		img = (*v)->spr_p;
	mlx_put_image_to_window((*v)->mlx, (*v)->win, img,
		(*v)->x * 16, (*v)->y * 16);
	if (loc_value == 'C')
		collectable(v);
	if ((loc_value == 'E') && ((*v)->collectable == (*v)->collectable_max))
		free_and_exit(v);
}

int	movement(int keycode, t_vars *vars)
{
	int	last_x;
	int	last_y;

	last_x = vars->x;
	last_y = vars->y;
	if (keycode == XK_Escape)
		free_and_exit(&vars);
	else if (keycode == XK_Up)
		update(&vars, 0, -1);
	else if (keycode == XK_Down)
		update(&vars, 0, 1);
	else if (keycode == XK_Left)
		update(&vars, -1, 0);
	else if (keycode == XK_Right)
		update(&vars, 1, 0);
	if ((last_x != vars->x || last_y != vars->y))
	{
		vars->move++;
		ft_printf("move: %d\n", vars->move);
	}
	return (0);
}

int	x_press( t_vars *vars)
{
	free_and_exit(&vars);
	return (0);
}

void	gameplay(char *map, t_vars *vars, int size, int height)
{
	int	fd;

	vars->x = 0;
	vars->y = 0;
	vars->wh = height;
	vars->ww = size - 2;
	vars->collectable = 0;
	vars->move = 0;
	fd = open(map, O_RDWR);
	vars->grid = create_map_matrix(fd, size, height);
	vars->collectable_max = count_collectable(vars->grid);
	find_player_position(vars->grid, &vars->x, &vars->y, height);
	mlx_hook(vars->win, 2, 1L << 0, movement, vars);
	mlx_hook(vars->win, 17, 0L, x_press, vars);
}
