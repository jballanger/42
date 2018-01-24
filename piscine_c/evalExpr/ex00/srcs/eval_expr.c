/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 08:30:55 by jballang          #+#    #+#             */
/*   Updated: 2016/09/17 12:33:56 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int		eval_expr(char *expr)
{
	int		nbr;
	int		more;
	int		i;
	int		n;

	nbr = 0;
	i = 0;
	n = 0;
	more = 0;
	while (expr[i] != '\0')
	{
		if (expr[i] == '(')
		{
			n = i;
			while (expr[n] != ')')
			{
				n++;
				if (expr[n] == '(')
					more++;
				if (expr[n] == ')' && more == 0)
					nbr = calc(expr, i, n);
				else if (expr[n] == ')')
					more--;
			}
		}
		i++;
	}
	return (nbr);
}
