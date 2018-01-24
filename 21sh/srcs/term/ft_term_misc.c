/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 09:21:42 by jballang          #+#    #+#             */
/*   Updated: 2017/06/02 14:06:31 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reset(t_term *term)
{
	int		i;

	i = 0;
	tputs(tgetstr("dl", NULL), 1, int_putchar);
	while (term->x > 0)
	{
		tputs(tgetstr("le", NULL), 1, int_putchar);
		term->x--;
	}
	ft_putstr("$> ");
	term->x = 3;
	while (term->cmd[i])
	{
		write(0, &term->cmd[i++], 1);
		term->x++;
	}
}

void	ft_repos_cursor(int x, int col, int cmdlen)
{
	int		tmpcol;

	while (cmdlen > x)
	{
		tmpcol = col;
		if ((cmdlen - 1) % col == 0 && x % col != 0)
		{
			tputs(tgetstr("up", NULL), 1, int_putchar);
			while (tmpcol > 0)
			{
				tputs(tgetstr("nd", NULL), 1, int_putchar);
				tmpcol--;
			}
		}
		else if (cmdlen % col != 0)
			tputs(tgetstr("le", NULL), 1, int_putchar);
		cmdlen--;
	}
}

void	ft_rewrite_cmd(t_term *term)
{
	int		i;
	int		tmpx;

	tmpx = term->x;
	ft_move_home(term);
	term->x = tmpx;
	tputs(tgetstr("cd", NULL), 1, int_putchar);
	term->max_x = term->prompt_len;
	i = 0;
	while (term->cmd && term->cmd[i])
	{
		write(0, &term->cmd[i++], 1);
		term->max_x++;
	}
	if (term->x < term->max_x)
		ft_repos_cursor(term->x, term->col, \
			(int)ft_strlen(term->cmd) + term->prompt_len);
}
