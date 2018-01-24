/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:54:10 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:43:13 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		fake03(char *str, int x, int y)
{
	char	*real03;

	real03 = (char*)malloc(sizeof(char) * (x * y));
	real03 = create_real03(x, y);
	if (ft_strcmp(str, real03) == 0)
		return (0);
	else
		return (1);
}
