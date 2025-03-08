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

int str_size(const char *s)
{
    size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while ((str[i] != '\0') && (str[i] != '\r'))
		i++;
	return (i);
}

int matrix_height(char **grid)
{
    int i;

    i = 0;
    while (grid[i] != NULL)
        i++;
    return(i);
}

void find_player_position(char **matrix, int *i, int *j, int height)
{
    int size;

    size = str_size(matrix[0]);
    while (*j < height)
    {
        while(*i < size)
        {
            if(matrix[*j][*i] == 'P')
                break;
            (*i)++;
        }
        if(matrix[*j][*i] == 'P')
            break;
        *i = 0;
        (*j)++;
    }
}