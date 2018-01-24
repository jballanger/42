/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:50:23 by mkrakows          #+#    #+#             */
/*   Updated: 2016/09/21 21:29:31 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		**carre(int t, int x, int y, int **tab)
{
	int i;
	int j;

	i = x - t + 1;
	while (i <= x)
	{
		j = y - t + 1;
		while (j <= y)
		{
			tab[i][j] = -1;
			j++;
		}
		i++;
	}
	return (tab);
}

void	print_table(char info[3], int **tab, int xmax, int ymax)
{
	int i;
	int j;

	i = 0;
	while (i < xmax)
	{
		j = 0;
		while (j < ymax)
		{
			if (tab[i][j] == 0)
				write(1, &info[1], 1);
			else if (tab[i][j] < 0)
				write(1, &info[2], 1);
			else if (tab[i][j] > 0)
				write(1, &info[0], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	find(char infos[3], int xmax, int ymax, int **tab)
{
	int i;
	int j;
	int tmp;
	int tmp2;
	int tmp3;

	tmp = 0;
	i = 0;
	while (i < xmax)
	{
		j = 0;
		while (j < ymax)
		{
			if (tab[i][j] > tmp)
			{
				tmp2 = i;
				tmp3 = j;
				tmp = tab[i][j];
			}
			j++;
		}
		i++;
	}
	tab = carre(tmp, tmp2, tmp3, tab);
	print_table(infos, tab, xmax, ymax);
}

int		min(int i, int j, int k)
{
	int nb;

	if (i <= j && i <= k)
		nb = i;
	else if (j <= i && j <= k)
		nb = j;
	else
		nb = k;
	return (nb + 1);
}

void	search(char infos[3], int **tab, int xmax, int ymax)
{
	int x;
	int y;

	x = 1;
	while (x < xmax)
	{
		y = 1;
		while (y < ymax)
		{
			while (tab[x][y] == 0 && y <= ymax)
				y++;
			tab[x][y] = min(tab[x - 1][y - 1], tab[x - 1][y], tab[x][y - 1]);
			y++;
		}
		x++;
	}
	find(infos, xmax, ymax, tab);
}
