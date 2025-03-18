/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:09:35 by erocha-l          #+#    #+#             */
/*   Updated: 2024/10/29 14:09:35 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_putnbr_ptr_fd(unsigned long n, int fd, char *base, int *count)
{
	if (n > 15)
	{
		ft_putnbr_ptr_fd ((n / 16), fd, base, count);
		ft_putnbr_ptr_fd ((n % 16), fd, base, count);
	}
	else
	{
		n = base[n];
		*count += write (fd, &n, 1);
	}
}

void	convert_ptr(void *ptr, int *count)
{
	unsigned long	num;

	if (ptr == NULL)
	{
		*count += write (1, "(nil)", 5);
		return ;
	}
	num = (unsigned long ) ptr;
	*count += write (1, "0", 1);
	*count += write (1, "x", 1);
	ft_putnbr_ptr_fd(num, 1, "0123456789abcdef", count);
}
