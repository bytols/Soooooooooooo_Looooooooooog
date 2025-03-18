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

void	free_matrix(char ***matrix)
{
	int		j;

	j = 0;
	while ((*matrix)[j] != NULL)
	{
		free((*matrix)[j]);
		j++;
	}
	free(*matrix);
	return ;
}

void	free_partial_matrix(char ***matrix, int last)
{
	int		j;

	j = 0;
	while (j < last)
	{
		free((*matrix[j]));
		j++;
	}
	free((*matrix));
}

char	**create_map_matrix(int fd, int size, int height)
{
	char	**matrix;
	char	*line;
	int		i;

	i = 0;
	matrix = malloc(sizeof(char *) * (height + 1));
	if (matrix == NULL)
		return (NULL);
	while (i < height)
	{
		line = get_next_line(fd);
		matrix[i] = malloc(sizeof(char) * (size + 1));
		if (matrix[i] == NULL)
		{
			free_partial_matrix(&matrix, i);
			return (NULL);
		}
		ft_strlcpy(matrix[i], line, (size + 1));
		free(line);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	dfs(char **grid, int j, int i, t_map_values_fd *map)
{
	int	n;
	int	h;

	h = matrix_height(grid);
	n = str_size(grid[0]);
	if ((i < 0) || (i >= n) || (j < 0) || (j >= h) || (grid[j][i] == '1'))
		return ;
	else
	{
		if (grid[j][i] == 'C')
			map->collectable++;
		else if (grid[j][i] == 'P')
			map->player++;
		else if (grid[j][i] == 'E')
			map->exit++;
		grid[j][i] = '1';
		dfs(grid, j + 1, i, map);
		dfs(grid, j - 1, i, map);
		dfs(grid, j, i + 1, map);
		dfs(grid, j, i - 1, map);
	}
}

int	flood_fill(int size, int height, char *map_path, t_map_values map_full)
{
	int				fd;
	char			**matrix;
	int				j;
	t_map_values_fd	map_v;

	map_v.collectable = 0;
	map_v.exit = 0;
	map_v.player = 0;
	j = 0;
	fd = open(map_path, O_RDWR);
	matrix = create_map_matrix(fd, size, height);
	if (matrix == NULL)
		return (0);
	find_player_position(matrix, &size, &j, height);
	dfs(matrix, j, size, &map_v);
	close(fd);
	free_matrix(&matrix);
	if ((map_v.collectable != map_full.collectable)
		|| (map_v.exit != map_full.exit) || (map_v.player != map_full.player))
		return (0);
	return (1);
}
