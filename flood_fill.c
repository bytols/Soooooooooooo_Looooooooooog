/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:05:38 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/06 15:07:13 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_matrix(char *** matrix)
{
    (void) matrix;
    return ; 
}

char **create_map_matrix(int fd, int size, int height)
{
    char **matrix;
    char *line;
    int i;
    int j;

    i = 0;
    matrix = malloc(sizeof(char *) * (height + 1));
    while (i < height)
    {
        line = get_next_line(fd);
        matrix[i] = malloc(sizeof(char) * (size + 1));
        ft_strlcpy(matrix[i], line, size);
        i++;
    }
    matrix[i] = NULL;
    j = 0;
    i = 0;
    while(j < height)
    {
        while (i < size)
        {  
            printf("%c", matrix[j][i]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
    return(matrix);
}
void dfs(char **grid, int j, int i, t_map_values_fd *map)
{
    int n;
    int h;

    h = matrix_height(grid);
    n = str_size(grid[0]);
    printf("aqui está as dimensoes %d e %d\n", h , n);
    if ((i < 0) || (i >= n) || (j < 0) || (j >= h) || (grid[j][i] == '1'))
        return ;
    else 
    {
        //printf("grid atual %c\n" , grid[j][i]);
        if(grid[j][i] == 'C')
            map->collectable++;
        else if(grid[j][i] == 'P')
            map->player++;
        else if(grid[j][i] == 'E')
            map->exit++;
        grid[j][i] = '1';
        dfs(grid, j+1, i, map);
        dfs(grid, j-1, i, map);
        dfs(grid, j, i + 1, map);
        dfs(grid, j, i - 1, map);
    }
}

int flood_fill(int size, int height, char *map_path, t_map_values map_full)
{
    int fd;
    char **matrix;
    int j;
    t_map_values_fd map_v;

    map_v.collectable = 0;
    map_v.exit = 0;
    map_v.player = 0;
    j = 0;
    fd = open(map_path, O_RDWR);
    matrix = create_map_matrix(fd, size, height);
    find_player_position(matrix, &size, &j, height);
    printf("aqui está as posiçoes do jogador %d %d \n", j , size);
    dfs(matrix, j, size, &map_v);
    printf("aqui os valores depois da struct %d %d %d\n" , map_v.collectable, map_v.player, map_v.exit);
    printf("aqui os valores depois da struct map_full %d %d %d\n" , map_full.collectable, map_full.player, map_full.exit);
    if((map_v.collectable != map_full.collectable) || (map_v.exit != map_full.exit)
        || (map_v.player != map_full.player))
        return(0);
    printf("aqui os valores depois da struct %d %d %d\n" , map_v.collectable, map_v.player, map_v.exit);
    close(fd);
    return (1);
}
