/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logique.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 16:01:21 by gwitrand          #+#    #+#             */
/*   Updated: 2016/09/11 16:01:23 by gwitrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			absli(int k, int **grille, int i)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (grille[i][j] == k)
			return (0);
		j++;
	}
	return (1);
}

int			abscol(int k, int **grille, int j)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grille[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int			absblc(int k, int **grille, int i, int j)
{
	int ibis;
	int jbis;

	ibis = i - (i % 3);
	jbis = j - (j % 3);
	i = ibis;
	j = jbis;
	while (i < ibis + 3)
	{
		while (j < jbis + 3)
		{
			if (grille[i][j] == k)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
