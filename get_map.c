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

void	init_struct(t_map_values *valid, char *line)
{
	valid->first_line = ft_strdup(line);
	valid->length = str_size(line);
	valid->player = 0;
	valid->collectable = 0;
	valid->exit = 0;
	valid->height = 0;
	valid->walls = 0;
}

int	get_map(int fd, int size, char *map_path)
{
	char			*line;
	char			*temp;
	t_map_values	valid;

	line = get_next_line(fd);
	init_struct(&valid, line);
	temp = NULL;
	while (line)
	{
		free(temp);
		temp = ft_strdup(line);
		size = str_size(line);
		if (size != valid.length)
			valid.length = -1;
		check_elements(&valid, line);
		valid.height++;
		free(line);
		line = get_next_line(fd);
	}
	valid.last_line = temp;
	size = flood_fill(valid.length, valid.height, map_path, valid);
	if (size == 0)
		valid.walls = -1;
	size = check_valid(&valid);
	return (size);
}

void	check_elements(t_map_values *valid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			valid->collectable++;
		else if (str[i] == 'E')
			valid->exit++;
		else if (str[i] == 'P')
			valid->player++;
		else if ((str[i] != '0') && (str[i] != '1')
			&& (str[i] != '\n') && (str[i] != '\r'))
			valid->walls = -1;
		i++;
	}
	if ((str[0] != '1') || (str[i - 3] != '1'))
		valid->walls = -1;
}

int	check_valid(t_map_values *map)
{
	int	valid;
	int	i;

	valid = 1;
	i = 0;
	if ((map->player <= 0 || map->player > 1) || (map->collectable <= 0)
		|| (map->exit <= 0 || map->exit > 1))
		valid = 0;
	if (map->length == -1)
		valid = 0;
	if (map->length == map->height)
		valid = 0;
	if (map->walls == -1)
		valid = 0;
	while (map->first_line[i] && map->last_line[i])
	{
		if ((map->first_line[i] != '1') || (map->last_line[i] != '1'))
			valid = 0;
		i++;
	}
	free(map->first_line);
	free(map->last_line);
	return (valid);
}
