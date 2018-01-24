/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:50:54 by jballang          #+#    #+#             */
/*   Updated: 2017/06/02 15:04:48 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirect_left(char *cmd, char *file, char **newenv)
{
	int		fd;
	int		in;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_openfile_error(file, fd);
	else
	{
		if ((in = dup(0)) == -1)
			ft_leave("-error while dup(0)");
		if (dup2(fd, 0) == -1)
			ft_leave("-error while dup2(file, 0)");
		lexer(cmd, newenv);
		if (close(fd) == -1)
			ft_leave("-error while closing file fd");
		if (dup2(in, 0) == -1)
			ft_leave("-error while dup2(in, 0)");
		if (close(in) == -1)
			ft_leave("-error while closing in");
	}
	free(file);
}

char	*ft_heredoc_parser(char *cmd, int i)
{
	char	*key;
	int		j;

	key = ft_strnew((ft_strlen(cmd) - (size_t)i) + 1);
	j = 0;
	while (cmd[i] && is_space_tab(cmd[i]))
		i++;
	while (cmd[i] && !is_space_tab(cmd[i]))
	{
		key[j++] = cmd[i];
		i++;
	}
	key[j] = '\0';
	return (key);
}

char	*ft_here_after(char *cmd, int i)
{
	char	*tmp;

	while (cmd[i] && is_space_tab(cmd[i]))
		i++;
	while (cmd[i] && !is_space_tab(cmd[i]))
		i++;
	tmp = ft_strdup(&cmd[i]);
	return (tmp);
}

void	ft_double_left(char *cmd, char **newenv)
{
	int		i;
	char	*tmp;
	char	*here_cmd;
	char	*here_cmd2;
	char	*here_end;

	i = 0;
	while (cmd[i] != '<')
		i++;
	tmp = ft_heredoc_parser(cmd, i + 2);
	here_end = ft_strtrim(tmp);
	free(tmp);
	here_cmd = ft_strdup(cmd);
	here_cmd[i] = '\0';
	here_cmd2 = ft_here_after(cmd, i + 2);
	ft_heredoc(here_end, here_cmd, here_cmd2);
	free(here_end);
	ft_arrdel(newenv);
}
