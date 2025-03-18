/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:45:21 by erocha-l          #+#    #+#             */
/*   Updated: 2024/10/10 14:45:21 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)src;
	len_src = f_strlen(str);
	if (size > 0)
	{
		while ((i + 1) < size && (str[i] != '\0'))
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}
/*#include <string.h>
int main(){

	char src[] = "Erick Rocha";
	char dest[10];
	char dest2[10];
	size_t  size = sizeof(src);
	size_t size_src, size_src_true;

	printf("%ld\n" , size);
	printf("\nd %s\n" , dest);
	printf("\n%s\n" , dest2);
	size_src = ft_strlcpy(dest, src, 5);
	size_src_true = strlcpy(dest2, src, 5);
	printf(" %s\n" , dest);
	printf(" %s\n" , dest2);
	printf(" %ld\n" , size_src);
	printf(" %ld\n" , size_src_true);
	if (dest[11] == '\0')
	{
		printf(" null!\n");
		printf("dest1 %c\n" , dest[0]);
		printf("dest2 %c\n", dest2[0]);
	}
}*/