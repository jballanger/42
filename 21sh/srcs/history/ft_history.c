/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 10:37:53 by jballang          #+#    #+#             */
/*   Updated: 2017/06/02 14:02:45 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_history_back(t_term *term)
{
	if (term->history_pos > 0)
	{
		term->history_pos = 0;
		if (term->cmd)
			free(term->cmd);
		term->cmd = NULL;
		if (term->cmd_temp)
		{
			term->cmd = ft_strdup(term->cmd_temp);
			free(term->cmd_temp);
			term->cmd_temp = NULL;
		}
	}
}

void	ft_history_next(t_term *term)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = term->history;
	while (i < term->history_pos)
	{
		tmp = tmp->next;
		i++;
	}
	i = 0;
	if (term->history_pos < term->history_len)
		term->history_pos++;
	if (term->cmd)
		free(term->cmd);
	term->cmd = NULL;
	term->cmd = ft_strdup(tmp->content);
}

void	ft_history_top(t_term *term)
{
	if (term->heredocument == 0 && term->dquote == 0)
	{
		ft_move_home(term);
		if (term->cmd && ft_strlen(term->cmd) > 0 && term->history_pos == 0)
			term->cmd_temp = ft_strdup(term->cmd);
		if (term->history->content && term->history_pos < term->history_len)
			ft_history_next(term);
		ft_rewrite_cmd(term);
		if (term->cmd)
			term->max_x = (int)ft_strlen(term->cmd) + term->prompt_len;
		ft_move_end(term);
	}
}

void	ft_history_prev(t_term *term)
{
	int		i;
	t_list	*tmp;

	term->history_pos--;
	i = 1;
	tmp = term->history;
	while (i < term->history_pos)
	{
		tmp = tmp->next;
		i++;
	}
	i = 0;
	if (term->cmd)
		free(term->cmd);
	term->cmd = NULL;
	term->cmd = ft_strdup(tmp->content);
}

void	ft_history_bottom(t_term *term)
{
	if (term->heredocument == 0 && term->dquote == 0)
	{
		ft_move_home(term);
		if (term->history_pos - 1 > 0)
			ft_history_prev(term);
		else
			ft_history_back(term);
		ft_rewrite_cmd(term);
		if (term->cmd)
			term->max_x = (int)ft_strlen(term->cmd) + term->prompt_len;
		ft_move_end(term);
	}
}
