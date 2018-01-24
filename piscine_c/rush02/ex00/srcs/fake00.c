/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:23:21 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:42:47 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		fake00(char *str, int x, int y)
{
	char	*real00;

	real00 = (char*)malloc(sizeof(char) * (x * y));
	real00 = create_real00(x, y);
	if (ft_strcmp(str, real00) == 0)
		return (0);
	else
		return (1);
}
