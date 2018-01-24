/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 22:24:42 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 14:06:12 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	top(int x)
{
	if (x >= 2)
	{
		ft_putchar('o');
		while (x-- > 2)
			ft_putchar('-');
		ft_putchar('o');
	}
	else
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	mid(int x, int y)
{
	if (x >= 2 && y > 1)
	{
		ft_putchar('|');
		while (x-- > 2)
			ft_putchar(' ');
		ft_putchar('|');
	}
	else
	{
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void	bot(int x, int y)
{
	if (x >= 2 && y >= 2)
	{
		ft_putchar('o');
		while (x-- > 2)
			ft_putchar('-');
		ft_putchar('o');
	}
	else if (y > 1)
	{
		ft_putchar('o');
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
