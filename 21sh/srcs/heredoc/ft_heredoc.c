/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:19:45 by jballang          #+#    #+#             */
/*   Updated: 2017/06/06 11:37:38 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_heredoc(char *cmd)
{
	char	**hd;

	if (!g_term.heredoc)
		g_term.heredoc = ft_new_heredoc(cmd);
	else
	{
		hd = ft_modify_heredoc(g_term.heredoc, cmd);
		ft_arrdel(g_term.heredoc);
		g_term.heredoc = hd;
	}
}

void	ft_here_exec(char *cmd)
{
	if (g_term.cmd)
		free(g_term.cmd);
	g_term.cmd = ft_strdup(cmd);
	lexer(cmd, NULL);
	if (g_term.heredoc_cmd)
	{
		free(g_term.heredoc_cmd[0]);
		free(g_term.heredoc_cmd[1]);
		free(g_term.heredoc_cmd);
		free(g_term.heredoc_end);
	}
	g_term.heredoc_cmd = NULL;
	g_term.heredoc_end = NULL;
	ft_here_clean();
}

void	heredoc_end(void)
{
	int		len;
	char	*tmp;
	char	*first_cmd;
	char	*cmd;

	len = ft_count(g_term.heredoc);
	tmp = ft_arrcpy(g_term.heredoc, len);
	first_cmd = ft_strjoin("echo \"", tmp);
	free(tmp);
	cmd = ft_here_merge(first_cmd);
	free(first_cmd);
	first_cmd = NULL;
	g_term.heredocument = 0;
	g_term.x = 3;
	g_term.max_x = 3;
	g_term.min_x = 3;
	g_term.prompt_len = 3;
	ft_here_exec(cmd);
	free(cmd);
}

void	heredoc_loop(char *cmd)
{
	if (ft_strcmp(cmd, g_term.heredoc_end) == 0)
		heredoc_end();
	else
	{
		add_heredoc(cmd);
		g_term.x = 9;
		g_term.max_x = 9;
		g_term.min_x = 9;
		ft_putstr("heredoc> ");
	}
}

void	ft_heredoc(char *here_end, char *cmd, char *cmd2)
{
	char	buff[6];
	ssize_t	ret;

	ft_heresafeclear(&g_term);
	g_term.heredoc_end = ft_strdup(here_end);
	g_term.heredoc_cmd = ft_joincmd(cmd, cmd2);
	free(cmd);
	free(cmd2);
	g_term.heredocument = 1;
	g_term.x = 9;
	g_term.max_x = 9;
	g_term.min_x = 9;
	g_term.prompt_len = 9;
	ft_putstr("heredoc> ");
	free(g_term.cmd);
	g_term.cmd = NULL;
	while (g_term.heredocument == 1 && (ret = read(0, buff, 6)))
	{
		if (g_term.heredocument == 1)
		{
			ft_columns(&g_term);
			ft_read_key(buff, &g_term, g_term.prompt_len);
		}
	}
}
