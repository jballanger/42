/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:07:50 by jballang          #+#    #+#             */
/*   Updated: 2017/03/29 11:06:12 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"

int		get_envkey(char *key)
{
	int			i;
	char		tmp[4096];
	extern char	**environ;

	i = 0;
	ft_bzero(tmp, 4096);
	ft_strcpy(tmp, key);
	tmp[ft_strlen(tmp) + 1] = '\0';
	tmp[ft_strlen(tmp)] = '=';
	while (environ[i])
	{
		if (ft_strncmp(environ[i], tmp, ft_strlen(tmp)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_arrdel(char **arr)
{
	int		i;

	i = 0;
	if (arr && ft_length(arr) > 0)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

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
		input = parser(buff, path, newenv);
		if (newenv && input[0])
			execve(input[0], &input[0], newenv);
		else if (input[0])
			execve(input[0], &input[0], environ);
		ft_arrdel(input);
	}
	ft_arrdel(path);
}

void	minishell_loop(char *buff, char **newenv)
{
	char	*cmd;
	pid_t	father;

	cmd = ft_strtrim(buff);
	father = 0;
	if (is_builtins(cmd))
		(newenv) ? (builtins(cmd, newenv)) : (builtins(cmd, NULL));
	else if (!is_blank(cmd))
	{
		(newenv) ? (minishell(cmd, father, newenv)) : \
		(minishell(cmd, father, NULL));
		wait(&father);
	}
	free(cmd);
}

void	ft_fg(int i)
{
	if (i < 1)
		ft_putstr("$> ");
}

int		main(void)
{
	char		*line;
	char		**buff;
	int			i;
	extern char	**environ;

	environ = ft_cpyenv();
	ft_putstr("$> ");
	while ((i = get_next_line(0, &line)))
	{
		ft_fg(i);
		if (i > 0)
		{
			i = 0;
			buff = ft_separator(line);
			while (buff[i])
			{
				minishell_loop(buff[i], NULL);
				free(buff[i++]);
			}
			ft_putstr("$> ");
			free(buff);
			free(line);
		}
	}
	return (0);
}
