/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:48:29 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/08 11:48:29 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	game(char *map, int fd)
{
	t_vars	vars;
	char	*line;

	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	vars.ww = str_size(line);
	vars.wh = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		vars.wh++;
	}
	free(line);
	close(fd);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.ww * 16), (vars.wh * 16), "game");
	if (vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
	render_map(map, &vars);
	gameplay(map, &vars, vars.ww, vars.wh);
	mlx_loop(vars.mlx);
}

void	render_map(char *map_name, t_vars *window)
{
	int		i;
	int		fd;
	int		height;
	char	*line;

	i = 0;
	height = 0;
	fd = open(map_name, O_RDWR);
	line = get_next_line(fd);
	init_img(&window);
	while (line != NULL)
	{
		window->height = height;
		render_line(line, &window, i);
		height += 16;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

void	render_line(char *line, t_vars **win, int i)
{
	void	*img;
	int		x_pos;
	int		y_pos;

	x_pos = 0;
	y_pos = (*win)->height;
	img = NULL;
	while ((line[i] != '\n') && (line[i] != '\0'))
	{
		if (line[i] == '0')
			img = (*win)->spr_g;
		else if (line[i] == 'C')
			img = (*win)->spr_c;
		else if (line[i] == 'P')
			img = (*win)->spr_p;
		else if (line[i] == '1')
			img = (*win)->spr_r;
		else if (line[i] == 'E')
			img = (*win)->spr_e;
		mlx_put_image_to_window((*win)->mlx, (*win)->win, img, x_pos, y_pos);
		i++;
		x_pos += 16;
	}
}

void	init_img(t_vars **w)
{
	(*w)->spr_g = mlx_xpm_file_to_image((*w)->mlx,
			"sprites/ground.xpm", &(*w)->width, &(*w)->height);
	(*w)->spr_c = mlx_xpm_file_to_image((*w)->mlx,
			"sprites/collectable.xpm", &(*w)->width, &(*w)->height);
	(*w)->spr_p = mlx_xpm_file_to_image((*w)->mlx,
			"sprites/player.xpm", &(*w)->width, &(*w)->height);
	(*w)->spr_r = mlx_xpm_file_to_image((*w)->mlx,
			"sprites/rock.xpm", &(*w)->width, &(*w)->height);
	(*w)->spr_e = mlx_xpm_file_to_image((*w)->mlx,
			"sprites/exit.xpm", &(*w)->width, &(*w)->height);
	(*w)->spr_pe = mlx_xpm_file_to_image((*w)->mlx,
			"sprites/player_exit.xpm", &(*w)->width, &(*w)->height);
	return ;
}

void	free_img(t_vars **w)
{
	mlx_destroy_image((*w)->mlx, (*w)->spr_g);
	mlx_destroy_image((*w)->mlx, (*w)->spr_c);
	mlx_destroy_image((*w)->mlx, (*w)->spr_p);
	mlx_destroy_image((*w)->mlx, (*w)->spr_r);
	mlx_destroy_image((*w)->mlx, (*w)->spr_e);
	mlx_destroy_image((*w)->mlx, (*w)->spr_pe);
	return ;
}
