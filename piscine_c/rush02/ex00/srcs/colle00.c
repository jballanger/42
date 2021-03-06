/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 21:21:28 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:47:20 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	colle00(char *str)
{
	char	*name;
	int		i;
	int		x;
	int		y;
	int		w;

	name = "[colle-00]";
	i = 0;
	x = 0;
	y = 0;
	w = 0;
	while (str[i++] != '\n')
		x++;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	if (fake(str, name, x, y, w) < 1)
		printer(name, x, y, 1);
	else
		ft_putstr("aucune\n");
	free(str);
}
