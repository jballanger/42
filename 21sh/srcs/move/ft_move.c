/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:13:45 by jballang          #+#    #+#             */
/*   Updated: 2017/06/02 14:03:59 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_move_left(t_term *term)
{
	char	c;
	int		i;

	if (term->x > term->min_x)
	{
		if ((term->x % term->col) == 0)
		{
			tputs(tgetstr("up", NULL), 1, int_putchar);
			i = 0;
			while (i++ < term->col)
				tputs(tgetstr("nd", NULL), 1, int_putchar);
		}
		else
			tputs(tgetstr("le", NULL), 1, int_putchar);
		term->x--;
		c = term->cmd[term->x - term->prompt_len];
		if (term->copy_mode == 1)
			ft_move_left_copy(term, c);
	}
}

void	ft_move_right(t_term *term)
{
	char	c;

	if (term->x < term->max_x)
	{
		if (((term->x + 1) % term->col) == 0)
			tputs(tgetstr("do", NULL), 1, int_putchar);
		else
			tputs(tgetstr("nd", NULL), 1, int_putchar);
		c = term->cmd[term->x - term->prompt_len];
		term->x++;
		if (term->copy_mode == 1)
		{
			tputs(tgetstr("le", NULL), 1, int_putchar);
			tputs(tgetstr("me", NULL), 1, int_putchar);
			write(0, &c, 1);
			ft_remove_copy(term);
			tputs(tgetstr("mr", NULL), 1, int_putchar);
			if (((term->x) % term->col) == 0)
				tputs(tgetstr("do", NULL), 1, int_putchar);
		}
	}
}

void	ft_move_home(t_term *term)
{
	while (term->x > term->min_x)
		ft_move_left(term);
}

void	ft_move_end(t_term *term)
{
	while (term->x < term->max_x)
		ft_move_right(term);
}

void	ft_move(t_term *term, char *buff)
{
	if (buff[0] == -61 && buff[1] == -89)
		ft_alt(term, buff);
	else if (buff[2] == 68)
		ft_move_left(term);
	else if (buff[2] == 67)
		ft_move_right(term);
	else if (buff[2] == 70)
		ft_move_end(term);
	else if (buff[2] == 72)
		ft_move_home(term);
	else if (buff[2] == 65)
		ft_history_top(term);
	else if (buff[2] == 66)
		ft_history_bottom(term);
	else if (buff[2] == 91 || buff[2] == -102 || buff[2] == 1)
		ft_alt(term, buff);
}
