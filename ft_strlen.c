/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:29:48 by erocha-l          #+#    #+#             */
/*   Updated: 2024/08/01 17:08:31 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*#include<stdio.h>
#include<string.h>
 int main()
 {
 	char vetor3[10] = "aaa";
 	printf("%ld\n", ft_strlen(vetor3));
 	printf("%ld\n" , strlen(vetor3));
}*/
