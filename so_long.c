/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:23:58 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/18 15:23:58 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char *argv[])
{
	int	fd;
	int	size;
	int	result;

	size = 0;
	if (argc != 2)
		return (0);
	fd = ft_strlen(argv[1]);
	if (check_file_name(argv[1]) == 1)
		error_and_exit("Error\ninvalid map name", 23);
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		error_and_exit("Error\nfile descriptor error", 27);
	result = get_map(fd, size, argv[1]);
	close(fd);
	if (result == 0)
		error_and_exit("Error\nMap error", 16);
	game(argv[1], fd);
	return (0);
}

int	check_file_name(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
		{
			if ((s[i + 1]) && (s[i + 2]) && (s[i + 3]))
			{
				if ((s[i + 1] == 'b') && (s[i + 2] == 'e')
					&& (s[i + 3] == 'r') && (s[i + 4] == '\0'))
					return (0);
			}
		}
		i++;
	}
	return (1);
}

void	error_and_exit(char *str, int size)
{
	int	result;

	result = write(2, str, size);
	(void) result;
	exit(0);
}

void	collectable(t_vars **v)
{
	(*v)->collectable++;
	(*v)->grid[(*v)->y][(*v)->x] = '0';
}
