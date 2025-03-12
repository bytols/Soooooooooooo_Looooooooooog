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
char check_position(t_vars **t_vars, int x, int y)
{
    char location;
    int loc_x;
    int loc_y;

    loc_x = (*t_vars)->x;
    loc_y = (*t_vars)->y;
    loc_x += x;
    loc_y += y;
    printf("locx e locy %d %d  e tvars %d %d \n", loc_x , loc_y, (*t_vars)->window_width , (*t_vars)->window_height);
    if(loc_x < 0 || loc_y < 0 || loc_x > (*t_vars)->window_width || loc_y > (*t_vars)->window_height 
        || (*t_vars)->grid[loc_y][loc_x] == '1')
    {
        printf("retornei null!\n");
        return ('\0');
    }
    location = (*t_vars)->grid[loc_y][loc_x];
    (*t_vars)->x += x;
    (*t_vars)->y += y;
    return (location);
}


void update(t_vars **vars, int x, int y)
{
    char    loc_value;
    void    *img;
    int     last_x;
    int     last_y;

    last_x = (*vars)->x;
    last_y = (*vars)->y;
    loc_value = check_position(vars, x, y);
    if ((*vars)->grid[last_y][last_x] == 'E')
        img = mlx_xpm_file_to_image((*vars)->mlx, "sprites/exit.xpm", &(*vars)->width, &(*vars)->height);
    else 
        img = mlx_xpm_file_to_image((*vars)->mlx, "sprites/ground.xpm", &(*vars)->width, &(*vars)->height);   
    mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, (last_x * 16), (last_y * 16));
    if (loc_value == 'E')
        img = mlx_xpm_file_to_image((*vars)->mlx, "sprites/player_exit.xpm", &(*vars)->width, &(*vars)->height);
    else 
        img = mlx_xpm_file_to_image((*vars)->mlx, "sprites/player.xpm", &(*vars)->width, &(*vars)->height);
    mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img,(*vars)->x * 16, (*vars)->y * 16);
    if(loc_value == 'C')
    {
        (*vars)->collectable++;
        (*vars)->grid[(*vars)->y][(*vars)->x] = 0;
    }
    if ((loc_value == 'E') && ((*vars)->collectable == (*vars)->collectable_max))
        mlx_destroy_display((*vars)->mlx); // maybe free rigth here not in game!
}

int movement(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		printf("fechei!\n");
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(0);
	}
	else if (keycode == XK_Up)
    {
        update(&vars, 0, -1);
    }
	else if (keycode == XK_Down)
    {
        update(&vars, 0, 1);
    }
	else if (keycode == XK_Left)
    {
        update(&vars, -1, 0);
    }
	else if (keycode == XK_Right)
    {
        update(&vars, 1, 0);
    }
	else
		printf("tecla pressionada! %d \n", keycode);
    vars->move++;
    printf("move: %d\n", vars->move);
	return (0);
}

int x_press( t_vars *vars)
{
    printf("fechei! pelo x!\n");
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}


void gameplay(char *map, t_vars *vars, int size, int height)
{
    int fd;
    int i;

    vars->x = 0;
    vars->y = 0;
    vars->window_height = height;
    vars->window_width = size - 2;
    vars->collectable = 0;
    vars->move = 0;
    fd = open(map, O_RDWR);
    i = 0;
    vars->grid = create_map_matrix(fd, size, height);
    vars->collectable_max = count_collectable(vars->grid);
    find_player_position(vars->grid, &vars->x, &vars->y, height);
    printf("altura x %d, y %d\n", vars->x, vars->y);
    while(vars->grid[i] != NULL)
    {
        printf("%s\n", vars->grid[i]);
        i++;
    }
    mlx_hook(vars->win, 2, 1L<<0, movement, vars);
    mlx_hook(vars->win, 17, 0L, x_press, vars);
}
