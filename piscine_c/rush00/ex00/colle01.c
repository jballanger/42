/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:36:20 by jballang          #+#    #+#             */
/*   Updated: 2016/09/17 17:47:17 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top(int x)
{
	if (x >= 2)
	{
		ft_putchar('/');
		while (x-- > 2)
			ft_putchar('*');
		ft_putchar('\\');
	}
	else
	{
		ft_putchar('/');
	}
	ft_putchar('\n');
}

void	mid(int x, int y)
{
	if (x >= 2 && y > 1)
	{
		ft_putchar('*');
		while (x-- > 2)
			ft_putchar(' ');
		ft_putchar('*');
	}
	else
	{
		ft_putchar('*');
	}
	ft_putchar('\n');
}

void	bot(int x, int y)
{
	if (x >= 2 && y >= 2)
	{
		ft_putchar('\\');
		while (x-- > 2)
			ft_putchar('*');
		ft_putchar('/');
	}
	else if (y > 1)
	{
		ft_putchar('\\');
	}
	if (y > 1)
		ft_putchar('\n');
}

void	looper(int x, int y, int line)
{
	if (line <= y)
	{
		if (line == 1)
			top(x);
		if (line > 1 && line < y)
			mid(x, y);
		if (line == y)
			bot(x, y);
		line++;
		looper(x, y, line);
	}
}

void	colle(int x, int y)
{
	int	line;

	line = 1;
	if (x > 0 && y > 0)
		looper(x, y, line);
}
