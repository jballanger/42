/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 22:07:42 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 13:05:01 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	printer24(int x, int y)
{
	printer("[colle-02]", x, y, 0);
	ft_putstr(" || ");
	printer("[colle-04]", x, y, 1);
}

void	printer234(int x, int y)
{
	printer("[colle-02]", x, y, 0);
	ft_putstr(" || ");
	printer("[colle-03]", x, y, 0);
	ft_putstr(" || ");
	printer("[colle-04]", x, y, 1);
}

void	printer34(int x, int y)
{
	printer("[colle-03]", x, y, 0);
	ft_putstr(" || ");
	printer("[colle-04]", x, y, 1);
}

void	printer_final(char *name, int x, int y, int last)
{
	ft_putstr(name);
	ft_putchar(' ');
	ft_putchar('[');
	ft_putnbr(x);
	ft_putchar(']');
	ft_putchar(' ');
	ft_putchar('[');
	ft_putnbr(y);
	ft_putchar(']');
	if (last == 1)
		ft_putchar('\n');
}

void	printer(char *name, int x, int y, int last)
{
	char	*colle234;
	char	*colle24;
	char	*colle34;

	colle234 = "colle234";
	colle24 = "colle24";
	colle34 = "colle34";
	if (name == colle234)
		printer234(x, y);
	else if (name == colle24)
		printer24(x, y);
	else if (name == colle34)
		printer34(x, y);
	else
	{
		printer_final(name, x, y, last);
	}
}
