/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:52:11 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:45:16 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		fake01(char *str, int x, int y)
{
	char	*real01;

	real01 = (char*)malloc(sizeof(char) * (x * y));
	real01 = create_real01(x, y);
	if (ft_strcmp(str, real01) == 0)
		return (0);
	else
		return (1);
}
