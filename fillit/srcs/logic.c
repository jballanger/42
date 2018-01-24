/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:11:29 by jballang          #+#    #+#             */
/*   Updated: 2016/11/30 11:11:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*get_position(char **super)
{
	int			i;
	int			c;
	t_tetris	*list;

	i = 0;
	list = malloc(sizeof(t_tetris));
	while (super[i])
	{
		c = 0;
		list->p1 = pos_p1(super, i, 0, c);
		list->p2 = pos_p2(super, list->p1[0] + 1, list->p1[1], list->p1[2] + 1);
		list->p3 = pos_p3(super, list->p2[0] + 1, list->p2[1], list->p2[2] + 1);
		list->p4 = pos_p4(super, list->p3[0] + 1, list->p3[1], list->p3[2] + 1);
		list->next = malloc(sizeof(t_tetris));
		list->next->prev = list;
		list = list->next;
		i += 4;
	}
	list = list->prev;
	list->next = NULL;
	while (list->prev)
		list = list->prev;
	return (list);
}

void		logic(char *source)
{
	char		**super;
	char		**square;
	t_tetris	*list;
	int			p;
	int			i;

	p = 3;
	i = 0;
	super = ft_strsplit(source, '\n');
	list = place_it(get_position(super));
	square = make_square(list);
	square = solve_it(square, list);
	while (!square)
	{
		square = increase_size(square, p);
		square = solve_it(square, list);
		p++;
	}
	while (square[i][0] == '.' || ft_isalpha(square[i][0]))
	{
		ft_putendl(square[i]);
		i++;
	}
}
