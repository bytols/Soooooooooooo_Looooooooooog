/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:35:45 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/20 18:35:45 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h" 
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		closed;
	int		color;
	t_data	*img;
}	t_vars;

#endif