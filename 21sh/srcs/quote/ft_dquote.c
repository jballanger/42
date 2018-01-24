/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dquote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:36:38 by jballang          #+#    #+#             */
/*   Updated: 2017/06/02 14:49:48 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dquote_end(void)
{
	char	*tmp;

	tmp = ft_strdup(g_term.dquote_cmd);
	free(g_term.dquote_cmd);
	free(g_term.dquote_prompt);
	g_term.dquote_cmd = NULL;
	g_term.dquote_prompt = NULL;
	g_term.dquote = 0;
	g_term.x = 3;
	g_term.max_x = 3;
	g_term.min_x = 3;
	g_term.prompt_len = 3;
	main_loop(tmp);
	free(tmp);
	g_term.tr = 1;
}

void	dquote_add(char *cmd)
{
	char	*tmp;
	char	*tmp2;
	char	*pre_cmd;

	tmp = ft_strdup(g_term.dquote_cmd);
	tmp2 = ft_strdup(cmd);
	free(g_term.dquote_cmd);
	pre_cmd = ft_strjoin(tmp, "\n");
	g_term.dquote_cmd = ft_strjoin(pre_cmd, tmp2);
	free(tmp);
	free(tmp2);
	free(pre_cmd);
}

void	dquote_loop(char *cmd)
{
	int		q;

	if (g_term.prompt_len == 7)
		q = ft_count_quote(cmd, '\'');
	else
		q = ft_count_quote(cmd, '"');
	dquote_add(g_term.cmd);
	g_term.x = g_term.prompt_len;
	g_term.max_x = g_term.prompt_len;
	g_term.min_x = g_term.prompt_len;
	if (q % 2 == 1)
		dquote_end();
	else
		ft_putstr(g_term.dquote_prompt);
}

void	ft_dquote(char *cmd, char quote)
{
	char	buff[6];
	char	ret;

	g_term.dquote = 1;
	ft_dquotesafeclear(&g_term);
	if (quote == '\'')
		g_term.dquote_prompt = ft_strdup("quote> ");
	else
		g_term.dquote_prompt = ft_strdup("dquote> ");
	g_term.prompt_len = (int)ft_strlen(g_term.dquote_prompt);
	g_term.dquote_cmd = ft_strdup(cmd);
	ft_putstr(g_term.dquote_prompt);
	g_term.x = (int)ft_strlen(g_term.dquote_prompt);
	g_term.max_x = (int)ft_strlen(g_term.dquote_prompt);
	g_term.min_x = (int)ft_strlen(g_term.dquote_prompt);
	free(g_term.cmd);
	g_term.cmd = NULL;
	while (g_term.dquote == 1 && (ret = read(0, buff, 6)))
	{
		if (g_term.dquote == 1)
		{
			ft_columns(&g_term);
			ft_read_key(buff, &g_term, g_term.prompt_len);
		}
	}
}

int		ft_dquote_checker(char *cmd)
{
	int		s;
	int		d;
	int		i;
	char	q;

	s = ft_count_quote(cmd, '\'');
	d = ft_count_quote(cmd, '"');
	i = 0;
	if ((s > 0 && s % 2 == 1) || (d > 0 && d % 2 == 1))
	{
		while (cmd[i] != '\'' && cmd[i] != '"')
			i++;
		q = cmd[i];
		if (q == '\'' && s % 2 == 1)
			ft_dquote(cmd, q);
		else if (q == '"' && d % 2 == 1)
			ft_dquote(cmd, q);
		else if (s % 2 == 1)
			ft_dquote(cmd, '\'');
		else if (d % 2 == 1)
			ft_dquote(cmd, '"');
		return (1);
	}
	return (0);
}
