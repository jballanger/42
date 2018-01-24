/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:23:50 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 13:53:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_screen(t_term *term)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = term->x;
	tputs(tgetstr("dl", NULL), 1, int_putchar);
	tputs(tgetstr("cl", NULL), 1, int_putchar);
	if (term->prompt_len == 3)
		ft_putstr("$> ");
	else if (term->prompt_len == 7)
		ft_putstr("quote> ");
	else if (term->prompt_len == 8)
		ft_putstr("dquote> ");
	else if (term->prompt_len == 9)
		ft_putstr("heredoc> ");
	term->x = term->prompt_len;
	term->max_x = term->prompt_len;
	while (term->cmd && term->cmd[i])
	{
		term->x++;
		term->max_x++;
		write(0, &term->cmd[i++], 1);
	}
	while (term->x > tmp)
		ft_move_left(term);
}

void	ft_eof(t_term *term)
{
	if (!term->cmd || !term->cmd[0])
	{
		if (term->heredocument == 1)
		{
			heredoc_end();
			free(term->cmd);
			term->cmd = NULL;
		}
		else
		{
			ft_putendl("exit");
			ft_restore_term(&g_term.old_term);
			exit(0);
		}
	}
}

void	sigint_reset(t_term *term)
{
	if (term->heredocument == 1 || term->dquote == 1)
		g_term.tr = 1;
	term->x = 3;
	term->max_x = 3;
	term->min_x = 3;
	term->prompt_len = 3;
	term->heredocument = 0;
	term->dquote = 0;
	term->copy_mode = 0;
	tputs(tgetstr("me", NULL), 1, int_putchar);
	if (term->cmd)
		free(term->cmd);
	term->cmd = NULL;
}

void	int_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (g_term.child == 1)
			ft_putendl("^C");
		else
		{
			while (g_term.x < g_term.max_x)
			{
				ft_putchar('\n');
				g_term.x += g_term.col;
			}
			ft_putchar('\n');
			ft_putstr("$> ");
		}
		sigint_reset(&g_term);
	}
}
