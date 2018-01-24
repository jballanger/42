/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:43:10 by jballang          #+#    #+#             */
/*   Updated: 2017/03/01 13:00:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_envvar(char *var)
{
	int			envkey;
	char		*tmp;
	extern char	**environ;

	tmp = ft_strsub(var, 1, ft_strlen(var));
	envkey = get_envkey(tmp);
	free(tmp);
	tmp = NULL;
	if (envkey == -1)
		return (NULL);
	return (ft_strsub(environ[envkey], ft_strlen(var),\
		ft_strlen(environ[envkey])));
}

void	ft_echo(char **input)
{
	int		i;
	char	*tmp;

	i = 1;
	while (input[i])
	{
		if (input[i][0] == '$')
		{
			tmp = get_envvar(input[i]);
			ft_putstr(tmp);
			if (tmp && input[i + 1])
				ft_putchar(' ');
			free(tmp);
			tmp = NULL;
		}
		else
		{
			ft_putstr(input[i]);
			if (input[i + 1])
				ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}
