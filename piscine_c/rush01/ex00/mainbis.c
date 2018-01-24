/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 12:31:26 by gwitrand          #+#    #+#             */
/*   Updated: 2016/09/11 16:24:25 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putstr(char *str);
void	ft_putchar(char e);
void	affichage(int **grille);
int		check_erreur(int argc, char **argv);

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

int			estvalide(int **grille, int pos)
{
	int i;
	int j;
	int k;

	if (pos == 9 * 9)
		return (1);
	i = pos / 9;
	j = pos % 9;
	if (grille[i][j] != 0)
		return (estvalide(grille, pos + 1));
	k = 1;
	while (k <= 9)
	{
		if (absli(k, grille, i) && abscol(k, grille, j)
		&& absblc(k, grille, i, j))
		{
			grille[i][j] = k;
			if (estvalide(grille, pos + 1))
				return (1);
		}
		k++;
	}
	grille[i][j] = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	int	**grille;
	int	i;
	int	j;

	i = 1;
	if (check_erreur(argc, argv) > 0)
		return (0);
	grille = (int**)malloc(sizeof(int*) * 9);
	while (i < argc)
	{
		grille[i - 1] = (int*)malloc(sizeof(int) * 9);
		j = 0;
		while (argv[i][j] != '\0')
		{
			grille[i - 1][j] = (argv[i][j] - '0');
			if (grille[i - 1][j] == -2)
				grille[i - 1][j] = 0;
			j++;
		}
		i++;
	}

	ft_putstr("Grille avant\n");
	affichage(grille);
	estvalide(grille, 0);
	ft_putstr("Grille apres\n");
	affichage(grille);
	estvalide(grille, 0);
	ft_putstr("Grille apres V2\n");
	affichage(grille);
}
