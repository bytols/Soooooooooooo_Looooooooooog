/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:35:49 by erocha-l          #+#    #+#             */
/*   Updated: 2025/03/18 17:46:30 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	f_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static void	f_strncmp(char *dest, char *src, int *n)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[*n] = src[i];
		i++;
		(*n)++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = f_strlen(s1);
	len += f_strlen(s2);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	f_strncmp(ptr, (char *)s1, &i);
	f_strncmp(ptr, (char *)s2, &i);
	ptr[i] = '\0';
	return (ptr);
}