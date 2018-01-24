/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 10:48:53 by jballang          #+#    #+#             */
/*   Updated: 2017/03/16 15:28:31 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtins(char *cmd)
{
	if (ft_strncmp("echo", cmd, 4) == 0 ||\
		ft_strncmp("cd", cmd, 2) == 0 ||\
		ft_strncmp("setenv", cmd, 6) == 0 ||\
		ft_strncmp("unsetenv", cmd, 8) == 0 ||\
		ft_strncmp("env", cmd, 3) == 0 ||\
		ft_strncmp("exit", cmd, 4) == 0)
		return (1);
	return (0);
}

void	ft_tilde(char ***input, int i)
{
	char	**tmp;
	char	*home;
	char	cpy[512];

	tmp = *input;
	home = get_envvar("$HOME");
	while (tmp[i] && ft_strncmp(tmp[i], "~", 1) != 0)
		i++;
	if (tmp[i])
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

void	builtins(char *buff, char **newenv)
{
	char		**input;
	int			i;
	extern char	**environ;

	input = ft_strsplit(buff, ' ');
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
		exit(0);
	ft_arrdel(input);
}
