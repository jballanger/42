/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 12:02:17 by jballang          #+#    #+#             */
/*   Updated: 2017/05/22 14:01:12 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_splitrim(void)
{
	char	**ret;
	char	*tmp;
	int		i;

	ret = ft_strsplit_sh(g_term.cmd, '|');
	i = 0;
	while (ret[i])
	{
		tmp = ft_strtrim(ret[i]);
		free(ret[i]);
		ret[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (ret);
}

void	ft_pipe(char **newenv)
{
	char	**split_cmd;

	split_cmd = ft_splitrim();
	if (ft_length(split_cmd) < 2)
		ft_putendl("21sh: parse error near `|'");
	else
		ft_do_pipe(split_cmd, newenv);
	ft_arrdel(split_cmd);
}

void	minishell2(char *buff, char **newenv)
{
	int			envkey;
	char		**path;
	char		**input;
	char		*tmp;
	extern char	**environ;

	envkey = get_envkey("PATH");
	path = NULL;
	if (envkey != -1)
	{
		tmp = get_envvar("$PATH");
		path = ft_strsplit(tmp, ':');
		free(tmp);
	}
	input = parser(buff, path, newenv, 1);
	if (newenv && input[0])
		execve(input[0], &input[0], newenv);
	else if (input[0])
		execve(input[0], &input[0], environ);
	ft_arrdel(input);
	ft_arrdel(path);
}

void	pipe_exec(char *cmd, char **newenv)
{
	if ((ft_strchr(cmd, '<') || ft_strchr(cmd, '>')) && ft_is_redir())
	{
		g_term.piping = 1;
		ft_redirect_checker(cmd, newenv);
		g_term.piping = 0;
	}
	else
	{
		g_term.child = 1;
		if (is_builtins(cmd))
			(newenv) ? (builtins(cmd, newenv)) : (builtins(cmd, NULL));
		else if (!is_blank(cmd))
		{
			(newenv) ? (minishell2(cmd, newenv)) : \
			(minishell2(cmd, NULL));
		}
		g_term.child = 0;
	}
}
