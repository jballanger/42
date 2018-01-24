/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_real01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:37:18 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:44:09 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	top01(char *real, int x)
{
	if (x >= 2)
	{
		ft_strcat(real, '/');
		while (x-- > 2)
			ft_strcat(real, '*');
		ft_strcat(real, '\\');
	}
	else
	{
		ft_strcat(real, '/');
	}
	ft_strcat(real, '\n');
}

void	mid01(char *real, int x, int y)
{
	if (x >= 2 && y > 1)
	{
		ft_strcat(real, '*');
		while (x-- > 2)
			ft_strcat(real, ' ');
		ft_strcat(real, '*');
	}
	else
	{
		ft_strcat(real, '*');
	}
	ft_strcat(real, '\n');
}

void	bot01(char *real, int x, int y)
{
	if (x >= 2 && y >= 2)
	{
		ft_strcat(real, '\\');
		while (x-- > 2)
			ft_strcat(real, '*');
		ft_strcat(real, '/');
	}
	else if (y > 1)
	{
		ft_strcat(real, '\\');
	}
	if (y > 1)
		ft_strcat(real, '\n');
}

void	looper01(char *real, int x, int y, int line)
{
	if (line <= y)
	{
		if (line == 1)
			top01(real, x);
		if (line > 1 && line < y)
			mid01(real, x, y);
		if (line == y)
			bot01(real, x, y);
		line++;
		looper01(real, x, y, line);
	}
}

char	*create_real01(int x, int y)
{
	int		line;
	char	*real;

	line = 1;
	real = (char*)malloc(sizeof(char) * (x * y));
	if (x > 0 && y > 0)
		looper01(real, x, y, line);
	return (real);
}
