/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:16:45 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 11:47:15 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		child_process(char *cmd, int in, int out, int tbc)
{
	int		pid;

	tcsetattr(0, TCSADRAIN, &g_term.old_term);
	pid = fork();
	if (pid == 0)
	{
		if (tbc > -1)
			close(tbc);
		if (in != 0)
			dup2(in, 0);
		if (out != 1)
			dup2(out, 1);
		pipe_exec(cmd, NULL);
		exit(0);
	}
	tcsetattr(0, TCSADRAIN, &g_term.t);
	return (pid);
}

int		prepare_child(char **cmd, int *in, int *p, int i)
{
	int		ret;

	if (i == 0)
	{
		ret = child_process(cmd[i], 0, p[1], p[0]);
		close(p[1]);
		*in = p[0];
	}
	else if (cmd[i + 1])
	{
		ret = child_process(cmd[i], *in, p[1], p[0]);
		close(*in);
		close(p[1]);
		*in = p[0];
	}
	else
	{
		ret = child_process(cmd[i], *in, 1, -1);
		close(*in);
	}
	return (ret);
}

void	pipe_loop(char **cmd)
{
	int		i;
	int		in;
	int		p[2];
	int		pids[512];
	int		status;

	i = 0;
	in = 0;
	while (cmd[i])
	{
		pipe(p);
		if (i == 0)
			pids[i] = prepare_child(cmd, &in, p, i);
		else if (cmd[i + 1])
			pids[i] = prepare_child(cmd, &in, p, i);
		else
			pids[i] = prepare_child(cmd, &in, p, i);
		i++;
	}
	i = 0;
	while (cmd[i])
	{
		waitpid(pids[i], &status, 0);
		i++;
	}
}

void	ft_do_pipe(char **cmd, char **newenv)
{
	pipe_loop(cmd);
	if (newenv)
		ft_arrdel(newenv);
}
