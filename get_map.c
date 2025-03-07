/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:26:29 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/06 14:58:28 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int str_size(const char *s)
{
    size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while ((str[i] != '\0') && (str[i] != '\n'))
		i++;
	return (i);
}

int get_map(int fd)
{
    char    *line;
    int     size;
    t_map_values valid;
    
    line = get_next_line(fd);
    valid.player = 0;
    valid.collectable = 0;
    valid.exit = 0;
    valid.height = 0;
    valid.length = str_size(line);
    valid.first_line = line;
    valid.walls = 0;
    while(line)
    {
        valid.last_line = line;
        size = str_size(line);
        printf("%d  %s", size, line);
        if (size != valid.length)
            valid.length = -1;
        else
            valid.length = size;
        check_elements(&valid, line);
        valid.height++;
        line = get_next_line(fd);
    }
    size = check_valid(valid);
    return (size);
}

void check_elements(t_map_values *valid, char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] == 'C')
            valid->collectable++;
        else if(str[i] == 'E')
            valid->exit++;
        else if(str[i] == 'P')
            valid->player++;
        else if((str[i] != '0') && (str[i] != '1') && (str[i] != '\n'))
        {
            printf("definitivamente foi aqui %c\n" , str[i]);
            valid->walls = -1;
        }
        i++;
    }
    printf("vendo se peguei correto %d e %d e %d e %c e %c \n", valid->player , valid->collectable, valid->exit, str[0], str[i - 2]);
    if((str[0] != '1') || (str[i - 2] != '1'))
    {
        printf("definitivamente foi aqui  2 %c\n" , str[i]);
        valid->walls = -1;
    }
}

int check_valid(t_map_values map)
{
    int valid;
    int i;

    valid = 1;
    i = 0;
    printf("vendo se peguei correto 2 %d e %d e %d e %d\n", map.player , map.collectable, map.exit, map.walls);
    if((map.player <= 0 || map.player > 1) || (map.collectable <= 0)
            || (map.exit <= 0 || map.exit > 1))
    {
        printf("\nfoi aqui1\n");
        valid = 0;
    }
    if(map.length == -1)
    {
        printf("\nfoi aqui2\n");
        valid = 0;
    }
    if(map.length == map.height)
    {
        printf("\nfoi aqui3\n");
        valid = 0;
    }
    if(map.walls == -1)
    {
        printf("\nfoi aqui 4\n");
        valid = 0;
    }
    while(map.first_line[i] && map.last_line[i])
    {
        if((map.first_line[i] != '1') || (map.last_line[i] != '1'))
        {
            printf("\nfoi aqui 5\n");
            valid = 0;
        }
        i++;   
    }
    return(valid);
}
