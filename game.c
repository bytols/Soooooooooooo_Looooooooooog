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
    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, (vars.window_width * 16), (vars.window_height * 16), "Hello world!");
	if(vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
    render_map(map, &vars);
    mlx_loop(vars.mlx);
}

void render_map(char *map_name, t_vars *window)
{
    int fd;
    int height;
    char *line;

    height = 0;
    fd = open(map_name, O_RDWR );
    line = get_next_line(fd);
    while(line != NULL)
    {
        window->height = height;
        render_line(line, &window);
        height += 16;
        line = get_next_line(fd);
    }
}

void render_line(char *line, t_vars **window)
{
    int     i;
    t_data	img;
    int     x_pos;
    int     y_pos;

    img.img = mlx_new_image((*window)->mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    (*window)->img  = &img;
    i = 0;
    (*window)->width = 0;
    x_pos = 0;
    y_pos = (*window)->height;
    printf("width %d \n" , (*window)->height);
    while (line[i] != '\n')
    {
        if (line[i] == '0')
        {
            img.img = mlx_xpm_file_to_image((*window)->mlx, "sprites/ground.xpm", &(*window)->width, &(*window)->height);
            mlx_put_image_to_window((*window)->mlx, (*window)->win, img.img, x_pos, y_pos);
        }
        else if (line[i] == 'C')
        {
            img.img = mlx_xpm_file_to_image((*window)->mlx, "sprites/collectable.xpm", &(*window)->width, &(*window)->height);
            mlx_put_image_to_window((*window)->mlx, (*window)->win, img.img, x_pos, y_pos);
        }
        else if (line[i] == 'P')
        {
            img.img = mlx_xpm_file_to_image((*window)->mlx, "sprites/player.xpm", &(*window)->width, &(*window)->height);
            mlx_put_image_to_window((*window)->mlx, (*window)->win, img.img, x_pos, y_pos);
        }
        else if (line[i] == '1')
        {
            img.img = mlx_xpm_file_to_image((*window)->mlx, "sprites/rock.xpm", &(*window)->width, &(*window)->height);
            mlx_put_image_to_window((*window)->mlx, (*window)->win, img.img, x_pos, y_pos);
        }
        else if (line[i] == 'E')
        {
            img.img = mlx_xpm_file_to_image((*window)->mlx, "sprites/exit.xpm", &(*window)->width, &(*window)->height);
            mlx_put_image_to_window((*window)->mlx, (*window)->win, img.img, x_pos, y_pos);
        }
        i++;
        x_pos += 16;
    }
}
