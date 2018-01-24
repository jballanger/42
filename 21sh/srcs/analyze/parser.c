/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:30:05 by jballang          #+#    #+#             */
/*   Updated: 2017/05/24 11:24:10 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_exe(char *file, int leave)
{
	struct stat	st;

	if (lstat(file, &st) == 0)
	{
		if (!(st.st_mode & S_IXUSR) || (S_ISDIR(st.st_mode)))
		{
			if (leave)
			{
				ft_putstr("minishell: permission denied: ");
				ft_putendl(file);
				exit(0);
			}
		}
		else
			return (1);
	}
	return (0);
}

char	*ft_path(char *cmd, char **path, int leave)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (path && path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		if (open(tmp2, O_RDONLY) != -1 && is_exe(tmp2, 1))
		{
			free(cmd);
			free(tmp);
			return (tmp2);
		}
		free(tmp);
		free(tmp2);
		tmp = NULL;
		tmp2 = NULL;
		i++;
	}
	ft_putstr(cmd);
	ft_putendl(": command not found");
	(leave) ? (exit(0)) : (free(cmd));
	return (NULL);
}

int		ft_countword(char buff[])
{
	int		res;
	int		i;

	res = 1;
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == ' ')
		{
			res++;
			while (buff[i] == ' ')
				i++;
		}
		if (buff[i] != '\0')
			i++;
	}
	return (res);
}

void	ft_prepath(char **cmd, char **path, char **newenv, int leave)
{
	char	*tmp;
	char	*newenv_path;
	char	**newenv_path_split;

	tmp = ft_strdup(*cmd);
	free(*cmd);
	if (newenv)
	{
		newenv_path = get_newenvvar("$PATH", newenv);
		newenv_path_split = ft_strsplit(newenv_path, ':');
		*cmd = ft_path(tmp, newenv_path_split, leave);
		free(newenv_path);
		free(newenv_path_split);
	}
	else
		*cmd = ft_path(tmp, path, leave);
}

char	**parser(char *buff, char **path, char **newenv, int pp)
{
	char	**input;
	int		i;
	int		j;
	int		p;

	if (!(input = (char**)malloc(sizeof(char*) *\
		(unsigned long)(ft_countword(buff) + 1))))
		ft_leave(EMALLOC);
	j = 0;
	i = 0;
	while (buff[i] != '\0')
	{
		p = 0;
		while ((buff[i] == ' ' || buff[i] == '\t') && buff[i] != '\0')
			i++;
		input[j] = ft_strnew((size_t)ft_countwordlen(&buff[i]));
		while (buff[i] != ' ' && buff[i] != '\t' && buff[i] != '\0')
			input[j][p++] = buff[i++];
		input[j][p] = '\0';
		j++;
	}
	if ((open(input[0], O_RDONLY) == -1 || !(is_exe(input[0], 1))) && pp)
		ft_prepath(&input[0], path, newenv, 1);
	input[j] = NULL;
	return (input);
}
