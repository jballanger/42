/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:10:32 by jballang          #+#    #+#             */
/*   Updated: 2017/05/11 09:13:54 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_move_line_top(t_term *term)
{
	if (term->x > term->col)
	{
		tputs(tgetstr("up", NULL), 1, int_putchar);
		term->x -= term->col;
		while (term->x < 3)
		{
			tputs(tgetstr("nd", NULL), 1, int_putchar);
			term->x++;
		}
	}
}

void	ft_move_line_bot(t_term *term)
{
	int		i;

	if (term->max_x > term->col && term->x < (term->max_x - term->col))
	{
		i = term->x;
		while (i > term->col)
			i -= term->col;
		term->x += term->col;
		tputs(tgetstr("do", NULL), 1, int_putchar);
		while (i-- > 0)
			tputs(tgetstr("nd", NULL), 1, int_putchar);
		while (term->x > term->max_x)
		{
			tputs(tgetstr("nd", NULL), 1, int_putchar);
			term->x--;
		}
	}
}
