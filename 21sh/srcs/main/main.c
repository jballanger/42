/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:07:50 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 11:53:36 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(char *buff, pid_t father, char **newenv)
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
	father = fork();
	if (father == 0)
	{
		input = parser(buff, path, newenv, 1);
		if (newenv && input[0])
			execve(input[0], &input[0], newenv);
		else if (input[0])
			execve(input[0], &input[0], environ);
		ft_arrdel(input);
	}
	ft_arrdel(path);
}

void	minishell_loop(char *cmd, char **newenv, pid_t father)
{
	if (ft_strchr(cmd, '<') && ft_is_redir())
		ft_redirect_checker(cmd, newenv);
	else if (ft_strchr(cmd, '|') && ft_ispipe())
		ft_pipe(newenv);
	else
	{
		if ((ft_strchr(cmd, '>')) && ft_is_redir())
			ft_redirect_checker(cmd, newenv);
		else
		{
			if (ft_strlen(cmd) > 0 && is_builtins(cmd))
				(newenv) ? (builtins(cmd, newenv)) : (builtins(cmd, NULL));
			else if (!is_blank(cmd))
			{
				g_term.child = 1;
				tcsetattr(0, TCSADRAIN, &g_term.old_term);
				(newenv) ? (minishell(cmd, father, newenv)) : \
				(minishell(cmd, father, NULL));
				wait(&father);
				tcsetattr(0, TCSADRAIN, &g_term.t);
				g_term.child = 0;
			}
		}
	}
}

void	main_loop(char *line)
{
	int		i;
	char	**buff;

	i = 0;
	buff = ft_separator(line);
	while (buff[i])
	{
		if (g_term.cmd)
			free(g_term.cmd);
		g_term.cmd = buff[i];
		lexer(buff[i], NULL);
		i++;
	}
	if (g_term.heredocument == 0 && g_term.dquote == 0 && g_term.tr == 0)
		ft_putstr("$> ");
	g_term.tr = 0;
	free(buff);
}

int		main(void)
{
	extern char	**environ;

	ft_init_term(&g_term);
	environ = ft_cpyenv();
	if (signal(SIGINT, int_handler) == SIG_ERR)
		ft_leave("21sh: unable to catch SIGINT signal");
	ft_putstr("$> ");
	read_input(&g_term);
	return (0);
}
