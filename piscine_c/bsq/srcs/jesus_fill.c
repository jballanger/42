/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jesus_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:03:17 by jballang          #+#    #+#             */
/*   Updated: 2016/09/21 19:46:11 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_strline(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n - 1);
}

int		ft_strlen(char *str)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\n')
	{
		i++;
		l++;
	}
	return (l);
}

int		remove_infos(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	filler(char *buf, char infos[3], int x, int y)
{
	int		i;
	int		**buffer;

	buffer = malloc(sizeof(buffer) * ft_strline(buf));
	i = remove_infos(buf);
	buffer[0] = malloc(sizeof(buffer[0]) * ft_strlen(buf));
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			x++;
			buffer[x] = malloc(sizeof(buffer) * ft_strlen(buf));
			y = 0;
			i++;
		}
		if (buf[i] == infos[1])
			buffer[x][y] = 0;
		else
			buffer[x][y] = 1;
		y++;
		if (buf[i] != '\0')
			i++;
	}
	search(infos, buffer, get_x(buf), get_y(buf));
}

int		jesus_fill(char *buf, char infos[3])
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	filler(buf, infos, x, y);
	return (0);
}
