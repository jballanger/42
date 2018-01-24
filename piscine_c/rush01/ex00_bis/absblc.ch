/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absblc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 23:25:38 by gwitrand          #+#    #+#             */
/*   Updated: 2016/09/10 23:25:41 by gwitrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool		absblc(int k, int grille[9][9], int i, int j)
{
	int ibis;
	int jbis;

	ibis = i - (i % 3);
	jbis = j - (j % 3);
	i = ibis;
	while (i < ibis + 3)
	{
		while (j < jbis + 3)
		{
			if (grille[i][j] == k)
				j++;
			return (false);
		}
		i++;
	}
	return (true);
}
