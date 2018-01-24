/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:53:35 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:43:06 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		fake02(char *str, int x, int y)
{
	char	*real02;

	real02 = (char*)malloc(sizeof(char) * (x * y));
	real02 = create_real02(x, y);
	if (ft_strcmp(str, real02) == 0)
		return (0);
	else
		return (1);
}
