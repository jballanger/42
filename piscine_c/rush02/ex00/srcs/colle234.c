/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle234.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 21:47:31 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:48:21 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	checkprinter(char *str, char *name, int x, int y)
{
	int		w;

	w = 0;
	if (fake(str, name, x, y, w) < 1)
		printer(name, x, y, 1);
	else
		ft_putstr("aucune\n");
	free(str);
}

void	pre_printer(char *str, char *name, int x, int y)
{
	char	*colle02;
	char	*colle03;
	char	*colle04;

	colle02 = "[colle-02]";
	colle03 = "[colle-03]";
	colle04 = "[colle-04]";
	if (name == colle02)
	{
		if (x == 1 && y == 1)
			printer("colle234", x, y, 0);
		else if (x == 1 && y >= 2)
			printer("colle24", x, y, 0);
		else
			checkprinter(str, name, x, y);
	}
	else if (name == colle03)
	{
		if (x >= 1 && y == 1)
			printer("colle34", x, y, 0);
		else
			checkprinter(str, name, x, y);
	}
	else if (name == colle04)
		checkprinter(str, name, x, y);
}

void	colle34(char *str, int i, int x, int y)
{
	char	*name;

	while (str[i++] != '\n')
		x++;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			y++;
		}
		i++;
	}
	if (str[i - 2] == 'C')
		name = "[colle-03]";
	else
		name = "[colle-04]";
	pre_printer(str, name, x, y);
}

void	colle234(char *str)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (str[i] != '\n')
		i++;
	if (str[i - 1] == 'A' && i >= 1)
	{
		x = i;
		y = 1;
		while (str[i++] != '\0')
			if (str[i] == '\n')
				y++;
		pre_printer(str, "[colle-02]", x, y);
	}
	else
	{
		i = 0;
		x = 0;
		y = 0;
		colle34(str, i, x, y);
	}
}
