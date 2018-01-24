/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:06:04 by kstoian           #+#    #+#             */
/*   Updated: 2016/11/30 11:05:33 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*return_pos(int *p, int x, int y, int c)
{
	p[0] = x;
	p[1] = y;
	p[2] = c;
	return (p);
}

int		*pos_p1(char **super, int x, int y, int c)
{
	int	*p;

	p = (int*)malloc(sizeof(int) * 3);
	while (super[x][y] == '.')
	{
		if (c == 3)
		{
			c = 0;
			x -= 3;
			y++;
		}
		if (super[x][y] == '.')
		{
			x++;
			c++;
		}
	}
	return (return_pos(p, x, y, c));
}

int		*pos_p2(char **super, int x, int y, int c)
{
	int	*p;

	p = (int*)malloc(sizeof(int) * 3);
	if (c == 4)
	{
		c = 0;
		x -= 4;
		y++;
	}
	while (super[x][y] == '.')
	{
		if (c == 3)
		{
			c = 0;
			x -= 3;
			y++;
		}
		if (super[x][y] == '.')
		{
			x++;
			c++;
		}
	}
	return (return_pos(p, x, y, c));
}

int		*pos_p3(char **super, int x, int y, int c)
{
	int	*p;

	p = (int*)malloc(sizeof(int) * 3);
	if (c == 4)
	{
		c = 0;
		x -= 4;
		y++;
	}
	while (super[x][y] == '.')
	{
		if (c == 3)
		{
			c = 0;
			x -= 3;
			y++;
		}
		if (super[x][y] == '.')
		{
			x++;
			c++;
		}
	}
	return (return_pos(p, x, y, c));
}

int		*pos_p4(char **super, int x, int y, int c)
{
	int	*p;

	p = (int*)malloc(sizeof(int) * 3);
	if (c == 4)
	{
		c = 0;
		x -= 4;
		y++;
	}
	while (super[x][y] == '.')
	{
		if (c == 3)
		{
			c = 0;
			x -= 3;
			y++;
		}
		if (super[x][y] == '.')
		{
			x++;
			c++;
		}
	}
	return (return_pos(p, x, y, c));
}
