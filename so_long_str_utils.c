/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_str_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:15:39 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/08 00:15:39 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit(t_vars **vars)
{
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	mlx_destroy_display((*vars)->mlx);
	free((*vars)->mlx);
	free_matrix(&(*vars)->grid);
	exit(0);
}

int	str_size(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while ((str[i] != '\0') && (str[i] != '\r'))
		i++;
	return (i);
}

int	matrix_height(char **grid)
{
	int	i;

	i = 0;
	while (grid[i] != NULL)
		i++;
	return (i);
}

void	find_player_position(char **matrix, int *i, int *j, int height)
{
	int	size;

	size = str_size(matrix[0]);
	while (*j < height)
	{
		while (*i < size)
		{
			if (matrix[*j][*i] == 'P')
				break ;
			(*i)++;
		}
		if (matrix[*j][*i] == 'P')
			break ;
		*i = 0;
		(*j)++;
	}
}

int	count_collectable(char **grid)
{
	int	collectable;
	int	i;
	int	j;

	collectable = 0;
	i = 0;
	j = 0;
	while (grid[j] != NULL)
	{
		while (grid[j][i] != '\0')
		{
			if (grid[j][i] == 'C')
				collectable++;
			i++;
		}
		i = 0;
		j++;
	}
	return (collectable);
}
