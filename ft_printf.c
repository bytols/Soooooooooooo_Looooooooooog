/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:36:04 by erocha-l          #+#    #+#             */
/*   Updated: 2024/10/29 14:36:04 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	type(char c, va_list arguments, int *count)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(arguments, int), 1, count);
	if (c == 's')
		ft_putstr_fd(va_arg(arguments, char *), 1, count);
	if (c == 'd')
		ft_putnbr_fd(va_arg(arguments, int), 1, count);
	if (c == 'i')
		ft_putnbr_fd(va_arg(arguments, int), 1, count);
	if (c == 'u')
		ft_putunbr_fd(va_arg(arguments, unsigned int), 1, count);
	if (c == 'p')
		convert_ptr(va_arg(arguments, void *), count);
	if (c == 'x')
		ft_putb(va_arg(arguments, unsigned int), 1, "0123456789abcdef", count);
	if (c == 'X')
		ft_putb(va_arg(arguments, unsigned int), 1, "0123456789ABCDEF", count);
	if (c == '%')
		ft_putchar_fd('%', 1, count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	if (format == NULL)
		return (-1);
	va_start(arguments, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			type(format[i], arguments, &count);
		}
		else
			ft_putchar_fd(format[i], 1, &count);
		i++;
	}
	va_end(arguments);
	return (count);
}
