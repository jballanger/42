/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/04/19 15:32:11 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	main(int ac, char **av)
{
	int		length;
	int		i;
	char	c;
	char	*str;

	ac = 777;
	length = ft_atoi(av[2]);
	c = av[1][0];
	str = ft_malloc(length + 1);
	i = 0;
	while (i < length)
	{
		str[i] = c;
		i += 1;
	}
	str[i] = '\0';
	ft_putendl(str);
}
