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
char check_position(t_player **t_vars, int x, int y)
{
    char location;
    int loc_x;
    int loc_y;

    printf("aqui os x e y %d %d \n", x , y);
    loc_x = (*t_vars)->x;
    loc_y = (*t_vars)->y;
    printf("aqui os locx e locy %d %d \n", loc_x , loc_y);
    loc_x += x;
    loc_y += y;
    printf("aqui os locx e locy depois %d %d  e tvars %d %d \n", loc_x , loc_y, (*t_vars)->map_x , (*t_vars)->map_y);
    if(loc_x < 0 || loc_y < 0 || loc_x > (*t_vars)->map_x || loc_y > (*t_vars)->map_y)
    {
        printf("retornei null!\n");
        return ('\0');
    }
    location = (*t_vars)->grid[y][x];
    printf("aqui! %c\n" ,location);
    return (location);
}


void update(t_player **vars, int x, int y)
{
    char    loc_value;

    loc_value = check_position(vars, x, y);
    printf("local: %c\n", loc_value);
}

int movement(int keycode, t_player *vars)
{
    printf("aqui os locx e locy no movement: %d %d \n", vars->x , vars->y);
	if (keycode == XK_Escape)
	{
		printf("fechei!\n");
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(0);
	}
	else if (keycode == XK_Up)
    {
		printf("tecla pressionada up! %d \n", keycode);
        update(&vars, 0, 1);
    }
	else if (keycode == XK_Down)
		printf("tecla pressionada down! %d \n", keycode);
	else if (keycode == XK_Left)
		printf("tecla pressionada left! %d \n", keycode);
	else if (keycode == XK_Right)
		printf("tecla pressionada rigth! %d \n", keycode);
	else
		printf("tecla pressionada! %d \n", keycode);
	return (0);
}

void gameplay(char *map, t_vars *vars, int size, int height)
{
    int fd;
    int i;
    t_player player;

    player.mlx = vars->mlx;
    player.win = vars->win;
    player.x = 0;
    player.y = 0;
    player.map_x = size;
    player.map_y = height;
    fd = open(map, O_RDWR);
    i = 0;
    player.grid = create_map_matrix(fd, size, height);
    find_player_position(player.grid, &player.x, &player.y, height);
    printf("altura x %d, y %d\n", player.x, player.y);
    while(player.grid[i] != NULL)
    {
        printf("%s\n", player.grid[i]);
        i++;
    }
    mlx_hook(player.win,2, 1L<<0, movement, &player);
}
