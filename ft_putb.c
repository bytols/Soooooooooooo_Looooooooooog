/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:32:55 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/18 17:14:42 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putb(unsigned int n, int fd, char *base, int *count)
{
	if (n < 0)
	{
		write (fd, "-", 1);
		*count += 1;
		n = -n;
	}
	if (n > 15)
	{
		ft_putb ((n / 16), fd, base, count);
		ft_putb ((n % 16), fd, base, count);
	}
	else
	{
		n = base[n];
		write (fd, &n, 1);
		*count += 1;
	}
}
