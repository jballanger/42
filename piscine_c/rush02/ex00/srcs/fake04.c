/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:54:45 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:45:25 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		fake04(char *str, int x, int y)
{
	char	*real04;

	real04 = (char*)malloc(sizeof(char) * (x * y));
	real04 = create_real04(x, y);
	if (ft_strcmp(str, real04) == 0)
		return (0);
	else
		return (1);
}
