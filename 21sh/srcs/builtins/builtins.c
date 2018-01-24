/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 11:52:38 by jballang          #+#    #+#             */
/*   Updated: 2017/06/07 14:37:27 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_first(char *str)
{
	unsigned long	i;
	char			*ret;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	ret = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		is_builtins(char *cmd)
{
	char	*tmp;
	char	*first;

	tmp = ft_strtrim(cmd);
	first = ft_get_first(tmp);
	if (tmp && first)
	{
		if (ft_strcmp("echo", first) == 0 ||\
			ft_strcmp("cd", first) == 0 ||\
			ft_strcmp("setenv", first) == 0 ||\
			ft_strcmp("unsetenv", first) == 0 ||\
			ft_strcmp("env", first) == 0 ||\
			ft_strcmp("exit", first) == 0)
		{
			free(tmp);
			free(first);
			return (1);
		}
	}
	free(tmp);
	free(first);
	return (0);
}

void	ft_tilde(char ***input, int i)
{
	char	**tmp;
	char	*home;
	char	cpy[512];

	tmp = *input;
	home = get_envvar("$HOME");
	while (home && tmp[i] && ft_strncmp(tmp[i], "~", 1) != 0)
		i++;
	if (home && tmp[i])
	{
		if (ft_strcmp(tmp[i], "~") == 0)
		{
			free(tmp[i]);
			tmp[i] = ft_strnew(ft_strlen(home));
			ft_strcpy(tmp[i], home);
		}
		else if (ft_strncmp(tmp[i], "~/", 2) == 0)
		{
			ft_strcpy(cpy, &tmp[i][1]);
			free(tmp[i]);
			tmp[i] = ft_strjoin(home, cpy);
		}
	}
	free(home);
}

char	**ft_strsplit_builtins(char *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		p;

	i = 0;
	p = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (ft_count_occ(s, c) + 2))))
		ft_leave(EMALLOC);
	while (s[p])
	{
		j = 0;
		if (!(arr[i] = (char*)malloc(sizeof(char) * (ft_cfrom(s, c, p) + 1))))
			ft_leave(EMALLOC);
		while (s[p] && (s[p] != c || ft_isquote(p)))
			arr[i][j++] = s[p++];
		arr[i++][j] = '\0';
		(s[p] == c) ? (p++) : (p);
	}
	return (ft_strsplit_sh_return(arr, i));
}

void	builtins(char *buff, char **newenv)
{
	char		**input;
	int			i;
	extern char	**environ;

	input = ft_strsplit_builtins(buff, ' ');
	i = 0;
	if (ft_strchr(buff, '~') && get_envkey("HOME"))
		ft_tilde(&input, i);
	if (ft_strcmp("echo", input[0]) == 0)
		ft_echo(input);
	else if (ft_strcmp("cd", input[0]) == 0)
		(newenv) ? (ft_cd(input, newenv)) : (ft_cd(input, environ));
	else if (ft_strcmp("setenv", input[0]) == 0)
		ft_setenv(input);
	else if (ft_strcmp("unsetenv", input[0]) == 0)
		ft_unsetenv(input);
	else if (ft_strcmp("env", input[0]) == 0)
		ft_env(input);
	else if (ft_strcmp("exit", input[0]) == 0)
		ft_exit(input);
	ft_arrdel(input);
}
