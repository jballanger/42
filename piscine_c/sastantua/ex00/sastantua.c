/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 10:01:55 by jballang          #+#    #+#             */
/*   Updated: 2016/09/04 17:27:18 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	pyramid(int size, int line, int base)
{
	
}

void	looper(int size, int line, int base)
{
	if (size > 0 && line <= size)
	{
		pyramid(size, line, base);
		line++;
		base++;
		looper(size, line, base);
	}
}

void	sastantua(int size)
{
	int	base;
	int	line;
	int max;

	base = 3;
	line = 1;
	max = base;
	looper(size, line, base);
}

int		main(void)
{
	sasatantua(1);
	return (0);
}
