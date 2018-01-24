/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:12:37 by jballang          #+#    #+#             */
/*   Updated: 2016/09/21 19:02:33 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		get_x(char *buf)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			x++;
		i++;
	}
	return (x - 1);
}

int		get_y(char *buf)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	while (buf[i] != '\n')
	{
		y++;
		i++;
	}
	return (y);
}
