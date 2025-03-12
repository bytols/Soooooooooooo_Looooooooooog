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

void	game(char *map)
{
    int fd;
    t_vars	vars;
    char *line;

    fd = open(map, O_RDWR);
    line = get_next_line(fd);
    vars.window_width = str_size(line);
    vars.window_height = 0;
    while(line)
    {
        line = get_next_line(fd);
        vars.window_height++;
    }
    close(fd);
    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.window_width * 16), (vars.window_height * 16), "Hello world!");
	if(vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
    render_map(map, &vars);
    printf("cheguei aqui!!1\n");
    gameplay(map, &vars, vars.window_width, vars.window_height);
    mlx_loop(vars.mlx);
    free(vars.mlx);
    printf("encerrei aqui!\n");
}

void render_map(char *map_name, t_vars *window)
{
    int i;
    int fd;
    int height;
    char *line;

    i = 0;
    height = 0;
    fd = open(map_name, O_RDWR );
    line = get_next_line(fd);
    while(line != NULL)
    {
        window->height = height;
        render_line(line, &window, i);
        height += 16;
        line = get_next_line(fd);
    }
}

void render_line(char *line, t_vars **window, int i)
{
    void	*img;
    int     x_pos;
    int     y_pos;

    x_pos = 0;
    y_pos = (*window)->height;
    img = NULL;
    while (line[i] != '\n')
    {
        if (line[i] == '0')
            img = mlx_xpm_file_to_image((*window)->mlx, "sprites/ground.xpm", &(*window)->width, &(*window)->height);
        else if (line[i] == 'C')
            img = mlx_xpm_file_to_image((*window)->mlx, "sprites/collectable.xpm", &(*window)->width, &(*window)->height);
        else if (line[i] == 'P')
            img = mlx_xpm_file_to_image((*window)->mlx, "sprites/player.xpm", &(*window)->width, &(*window)->height);
        else if (line[i] == '1')
            img = mlx_xpm_file_to_image((*window)->mlx, "sprites/rock.xpm", &(*window)->width, &(*window)->height);
        else if (line[i] == 'E')
            img = mlx_xpm_file_to_image((*window)->mlx, "sprites/exit.xpm", &(*window)->width, &(*window)->height);
        mlx_put_image_to_window((*window)->mlx, (*window)->win, img, x_pos, y_pos);
        i++;
        x_pos += 16;
    }
}
