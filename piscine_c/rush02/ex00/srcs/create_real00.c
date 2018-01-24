/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_real00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:37:18 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:43:52 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	top(char *real, int x)
{
	if (x >= 2)
	{
		ft_strcat(real, 'o');
		while (x-- > 2)
			ft_strcat(real, '-');
		ft_strcat(real, 'o');
	}
	else
	{
		ft_strcat(real, 'o');
	}
	ft_strcat(real, '\n');
}

void	mid(char *real, int x, int y)
{
	if (x >= 2 && y > 1)
	{
		ft_strcat(real, '|');
		while (x-- > 2)
			ft_strcat(real, ' ');
		ft_strcat(real, '|');
	}
	else
	{
		ft_strcat(real, '|');
	}
	ft_strcat(real, '\n');
}

void	bot(char *real, int x, int y)
{
	if (x >= 2 && y >= 2)
	{
		ft_strcat(real, 'o');
		while (x-- > 2)
			ft_strcat(real, '-');
		ft_strcat(real, 'o');
	}
	else if (y > 1)
	{
		ft_strcat(real, 'o');
	}
	if (y > 1)
		ft_strcat(real, '\n');
}

void	looper(char *real, int x, int y, int line)
{
	if (line <= y)
	{
		if (line == 1)
			top(real, x);
		if (line > 1 && line < y)
			mid(real, x, y);
		if (line == y)
			bot(real, x, y);
		line++;
		looper(real, x, y, line);
	}
}

char	*create_real00(int x, int y)
{
	int		line;
	char	*real;

	line = 1;
	real = (char*)malloc(sizeof(char) * (x * y));
	if (x > 0 && y > 0)
		looper(real, x, y, line);
	return (real);
}
