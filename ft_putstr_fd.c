/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:14:19 by erocha-l          #+#    #+#             */
/*   Updated: 2024/10/29 14:14:19 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_putstr_fd(char *c, int fd, int *count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c == NULL)
	{
		j = write(fd, "(null)", 6);
		*count += 6;
		return ;
	}
	while (c[i] != '\0')
	{
		j = write (fd, &c[i], 1);
		*count += 1;
		i++;
	}
	(void) j;
}
