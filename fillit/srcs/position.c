/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:27:38 by jballang          #+#    #+#             */
/*   Updated: 2016/11/25 17:49:28 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	top(char *source)
{
	int	c;
	int	x;

	c = 5;
	x = 0;
	if (*(source - 5))
	{
		while (c > 0)
		{
			if (*source == '\n')
				x++;
			source--;
			c--;
		}
		if (x > 1)
			return (0);
		if (*(source) == '#')
			return (1);
	}
	return (0);
}

int	bot(char *source)
{
	int	c;
	int	x;

	c = 5;
	x = 0;
	if (*(source + 5))
	{
		while (c > 0)
		{
			if (*source == '\n')
				x++;
			source++;
			c--;
		}
		if (x > 1)
			return (0);
		if (*(source) == '#')
			return (1);
	}
	return (0);
}

int	left(char *source)
{
	if (*(source - 1))
	{
		if (*(source - 1) == '#')
			return (1);
	}
	return (0);
}

int	right(char *source)
{
	if (*(source + 1))
	{
		if (*(source + 1) == '#')
			return (1);
	}
	return (0);
}

int	position(char *source)
{
	if (top(source) || bot(source) || left(source) || right(source))
		return (top(source) + bot(source) + left(source) + right(source));
	return (0);
}
