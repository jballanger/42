/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:03:24 by jballang          #+#    #+#             */
/*   Updated: 2017/03/13 13:13:11 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cpyenv(void)
{
	extern char	**environ;
	char		**newenv;
	int			i;

	i = 0;
	if (!(newenv = (char**)malloc(sizeof(char*) * (ft_length(environ) + 1))))
		ft_leave("malloc error: ft_env_func.c:22");
	while (environ[i])
	{
		if (!(newenv[i] = (char*)malloc(sizeof(char) \
			* (ft_strlen(environ[i]) + 1))))
			ft_leave("malloc error: ft_env_func.c:26");
		ft_bzero(newenv[i], ft_strlen(newenv[i]) + 1);
		ft_strcpy(newenv[i], environ[i]);
		i++;
	}
	newenv[i] = NULL;
	return (newenv);
}

char	**env_remove(char ***currenv, char *toremove)
{
	int		envkey;
	char	**tmpenv;

	tmpenv = *currenv;
	envkey = get_newenvkey(tmpenv, toremove);
	if (envkey != -1)
	{
		free(tmpenv[envkey]);
		tmpenv[envkey] = NULL;
		ft_newreorder(&tmpenv, envkey);
	}
	return (tmpenv);
}

void	env_reset(char ***newenv)
{
	char	**tmpenv;
	int		x;

	tmpenv = *newenv;
	x = 0;
	while (tmpenv[x])
	{
		free(tmpenv[x]);
		tmpenv[x] = NULL;
		x++;
	}
	free(*newenv);
	*newenv = NULL;
}

int		env_cmd(char **input, char **newenv)
{
	pid_t	father;
	char	*string;
	char	**buff;
	int		i;

	father = 5;
	string = arrtostr(input);
	buff = ft_separator(string);
	i = 0;
	while (buff[i])
	{
		minishell_loop(buff[i], newenv);
		free(buff[i++]);
	}
	free(string);
	free(buff);
	ft_arrdel(newenv);
	return (-42);
}

void	ft_newreorder(char ***newenv, int key)
{
	int			i;
	char		tmp[4096];
	char		**tmpenv;

	i = key;
	tmpenv = *newenv;
	while (tmpenv[i + 1])
	{
		ft_bzero(tmp, 4096);
		ft_strcpy(tmp, tmpenv[i + 1]);
		free(tmpenv[i]);
		tmpenv[i] = ft_strdup(tmp);
		i++;
	}
	free(tmpenv[i]);
	tmpenv[i] = NULL;
}
