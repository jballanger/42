/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_real03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:37:18 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:44:43 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	top03(char *real, int x)
{
	if (x >= 2)
	{
		ft_strcat(real, 'A');
		while (x-- > 2)
			ft_strcat(real, 'B');
		ft_strcat(real, 'C');
	}
	else
	{
		ft_strcat(real, 'A');
	}
	ft_strcat(real, '\n');
}

void	mid03(char *real, int x, int y)
{
	if (x >= 2 && y > 1)
	{
		ft_strcat(real, 'B');
		while (x-- > 2)
			ft_strcat(real, ' ');
		ft_strcat(real, 'B');
	}
	else
	{
		ft_strcat(real, 'B');
	}
	ft_strcat(real, '\n');
}

void	bot03(char *real, int x, int y)
{
	if (x >= 2 && y >= 2)
	{
		ft_strcat(real, 'A');
		while (x-- > 2)
			ft_strcat(real, 'B');
		ft_strcat(real, 'C');
	}
	else if (y > 1)
	{
		ft_strcat(real, 'A');
	}
	if (y > 1)
		ft_strcat(real, '\n');
}

void	looper03(char *real, int x, int y, int line)
{
	if (line <= y)
	{
		if (line == 1)
			top03(real, x);
		if (line > 1 && line < y)
			mid03(real, x, y);
		if (line == y)
			bot03(real, x, y);
		line++;
		looper03(real, x, y, line);
	}
}

char	*create_real03(int x, int y)
{
	int		line;
	char	*real;

	line = 1;
	real = (char*)malloc(sizeof(char) * (x * y));
	if (x > 0 && y > 0)
		looper03(real, x, y, line);
	return (real);
}
