/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:34:11 by jballang          #+#    #+#             */
/*   Updated: 2017/06/06 11:39:44 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_columns(t_term *term)
{
	struct winsize	w;

	if (term->child == 0 && term->piping == 0)
	{
		if (ioctl(0, TIOCGWINSZ, &w) == -1)
			ft_leave("21sh: unable to retrieve the number of columns");
		term->col = w.ws_col;
	}
}

void	ft_history_pos(t_term *term)
{
	ft_columns(term);
	term->history = ft_lstnew(NULL, 0);
	term->history_pos = 0;
	term->history_len = 0;
	term->min_x = 3;
	term->max_x = 3;
	term->x = 3;
	term->child = 0;
	term->piping = 0;
	term->prompt_len = 3;
	term->dquote = 0;
	term->heredocument = 0;
	term->tr = 0;
}

void	ft_restore_term(struct termios *term)
{
	if (tcsetattr(0, TCSADRAIN, term) == -1)
	{
		ft_putendl_fd("21sh: unable to set terminal attributes", 2);
		exit(0);
	}
}

void	ft_save_term(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		ft_leave("21sh: unable to get terminal attributes\
			in order to restore previous terminal");
}

void	ft_init_term(t_term *term)
{
	ft_save_term(&term->old_term);
	tgetent(NULL, "xterm-256color");
	if (tcgetattr(0, &term->t) == -1)
		ft_leave("21sh: unable to get terminal attributes");
	term->t.c_lflag &= ~(unsigned int)(ICANON | ECHO);
	term->t.c_cc[VMIN] = 1;
	term->t.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term->t) == -1)
		ft_leave("21sh: unable to set terminal attributes");
	term->quotes = NULL;
	term->backslash = NULL;
	term->copy_mode = 0;
	term->copy = NULL;
	term->cmd = NULL;
	term->cmd_temp = NULL;
	term->heredoc = NULL;
	term->dquote_cmd = NULL;
	term->dquote_prompt = NULL;
	ft_history_pos(term);
}
