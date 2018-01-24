/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 09:46:22 by jballang          #+#    #+#             */
/*   Updated: 2016/09/17 10:36:46 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		calc(char *expr, int start, int end)
{
	char	*extract;
	int		p;

	extract = (char*)malloc(sizeof(char) * (end - start));
	p = 0;
	while (start != end)
	{
		extract[p] = expr[start];
		start++;
		p++;
	}
	return (ft_atoi(extract));
}
