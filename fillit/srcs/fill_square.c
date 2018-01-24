/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:39:38 by kstoian           #+#    #+#             */
/*   Updated: 2016/11/30 15:06:54 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*decrement_pos(t_tetris *list, int i)
{
	list->p1[i]--;
	list->p2[i]--;
	list->p3[i]--;
	list->p4[i]--;
	return (list);
}

t_tetris	*place_it(t_tetris *list)
{
	int j;

	j = 0;
	while (list)
	{
		while (list->p1[1] > 0 && list->p2[1] > 0 && list->p3[1] > 0 && \
				list->p4[1] > 0)
			list = decrement_pos(list, 1);
		while (list->p1[0] > 0 && list->p2[0] > 0 && list->p3[0] > 0 && \
				list->p4[0] > 0)
			list = decrement_pos(list, 0);
		if (list->next)
			list = list->next;
		else
			break ;
	}
	while (list->prev)
		list = list->prev;
	return (list);
}

char		**increase_size(char **square, size_t length)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	if (!(new = (char**)malloc(sizeof(char*) * 104)))
		return (NULL);
	while (i < 104)
	{
		if (!(new[i] = (char*)malloc(sizeof(char) * 104)))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < length)
	{
		while (j < length)
			new[i][j++] = '.';
		new[i][j] = '\0';
		i++;
		j = 0;
	}
	new[103] = NULL;
	return (new);
}

int			solve_it_checker(char **square, t_tetris *list, int i, int j)
{
	if (square[i + list->p1[0]][j + list->p1[1]] &&\
		square[i + list->p1[0]][j + list->p1[1]] == '.' &&\
		square[i + list->p2[0]][j + list->p2[1]] &&\
		square[i + list->p2[0]][j + list->p2[1]] == '.' &&\
		square[i + list->p3[0]][j + list->p3[1]] &&\
		square[i + list->p3[0]][j + list->p3[1]] == '.' &&\
		square[i + list->p4[0]][j + list->p4[1]] &&\
		square[i + list->p4[0]][j + list->p4[1]] == '.')
		return (1);
	return (0);
}

char		**solve_it(char **square, t_tetris *list)
{
	int		i;
	int		j;
	char	letter;

	i = 0;
	j = 0;
	letter = 'A';
	ft_putnbr(ft_rrange(list));
	ft_putchar('\n');
	while (square[i] && list)
	{
		while (square[i][j] && list)
		{
			if (solve_it_checker(square, list, i, j))
			{
				square[i + list->p1[0]][j + list->p1[1]] = letter;
				square[i + list->p2[0]][j + list->p2[1]] = letter;
				square[i + list->p3[0]][j + list->p3[1]] = letter;
				square[i + list->p4[0]][j + list->p4[1]] = letter;
				letter++;
				list = list->next;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (list)
		return (NULL);
	return (square);
}

char		**make_square(t_tetris *list)
{
	char	**square;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(square = (char**)malloc(sizeof(char*) * 104)))
		return (NULL);
	while (i < 104)
	{
		if (!(square[i] = (char*)malloc(sizeof(char) * 104)))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		while (j < 2)
			square[i][j++] = '.';
		square[i][j] = '\0';
		i++;
		j = 0;
	}
	square[103] = NULL;
	return (square);
}
