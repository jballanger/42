/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 09:43:48 by jballang          #+#    #+#             */
/*   Updated: 2017/06/09 09:56:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_spot(char *cmd, char **newenv)
{
	pid_t	father;
	int		total_quotes;

	father = 0;
	total_quotes = ft_count_quote(cmd, '\'') + ft_count_quote(cmd, '"');
	if ((ft_strchr(cmd, '\'') || ft_strchr(cmd, '"')) &&\
		total_quotes > 0 && g_term.piping == 0)
	{
		if (g_term.quotes)
		{
			free(g_term.quotes);
			g_term.quotes = NULL;
		}
		ft_mark_quote(cmd, total_quotes, 0, 0);
		ft_order_quotes(&g_term);
		ft_remove_quotes(&cmd);
	}
	if (g_term.backslash)
	{
		free(g_term.backslash);
		g_term.backslash = NULL;
	}
	ft_mark_bs(cmd);
	ft_remove_bs(&cmd);
	minishell_loop(cmd, newenv, father);
}

void	lexer(char *buff, char **newenv)
{
	char	*cmd;

	cmd = ft_strtrim(buff);
	if (ft_dquote_checker(cmd))
		;
	else if (ft_quote_checker(cmd))
	{
		if (ft_strchr(cmd, '$'))
			ft_envvar(&cmd);
		ft_spot(cmd, newenv);
	}
	if (g_term.quotes)
	{
		free(g_term.quotes);
		g_term.quotes = NULL;
	}
	free(cmd);
}
