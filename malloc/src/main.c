/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/04/19 13:26:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_malloc(size_t size)
{
	t_block	b;
	t_block	last;
	size_t	s;

	b = NULL;
	s = size;
	// Align size of s
	if (base)
	{
		last = base;
		b = find_block(&last, s);
		if (b)
		{
			// Found a block, try to split
		}
		else
		{
			// No fitting block, extend heap
		}
	}
	else
	{
		// First malloc
		// Extend the heap
	}
	return (b);
}

int		main(int ac, char **av)
{
	int		length;
	int		i;
	char	c;
	char	*str;

	ac = 777;
	length = ft_atoi(av[2]);
	c = av[1][0];
	str = malloc(length + 1);
	i = 0;
	while (i < length)
	{
		str[i] = c;
		i += 1;
	}
	str[i] = '\0';
	ft_putendl(str);
	ft_putnbr(getpagesize());
	ft_putchar('\n');
}
