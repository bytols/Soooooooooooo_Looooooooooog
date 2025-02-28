/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:26:29 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/28 00:17:40 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_map(int fd)
{
    int     num;
    char    *buffer;

    buffer = malloc(sizeof(char) * 20);
    num = read(fd, buffer, 10);
    (void) buffer;
    (void) num;
}