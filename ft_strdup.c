/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:15:45 by erocha-l          #+#    #+#             */
/*   Updated: 2024/10/08 20:15:45 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	char	*str;

	len = 0;
	str = (char *) s;
	while (str[len] != '\0')
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
	{
		ptr[len] = str[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "abclorem ipsum dolor sit amet";
	char *ptr;

	ptr = ft_strdup(str);
	printf(":%s\n", ptr);
	if (ptr[29] == '\0')
	{
		printf("é null!\n");
	}
	
}*/