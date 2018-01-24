/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 12:43:10 by jballang          #+#    #+#             */
/*   Updated: 2017/05/19 11:29:33 by jballang         ###   ########.fr       */
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
	return (ft_strsub(environ[envkey], (unsigned int)ft_strlen(var),\
		ft_strlen(environ[envkey])));
}

char	*get_newenvvar(char *var, char **newenv)
{
	int		envkey;
	char	*tmp;

	tmp = ft_strsub(var, 1, ft_strlen(var));
	envkey = get_envkey(tmp);
	free(tmp);
	tmp = NULL;
	if (envkey == -1)
		return (NULL);
	return (ft_strsub(newenv[envkey], (unsigned int)ft_strlen(var),\
		ft_strlen(newenv[envkey])));
}

void	ft_echo_bs(char *str, int *pos)
{
	int		i;

	i = *pos;
	if (str[i - 1] && str[i - 1] == '\\')
	{
		ft_putchar(str[i]);
		*pos += 1;
	}
	else if (str[i + 1])
	{
		if (str[i + 1] == 'n')
		{
			ft_putchar('\n');
			*pos += 2;
		}
		else
		{
			ft_putchar(str[i + 1]);
			*pos += 2;
		}
	}
}

void	ft_print(char *str, int len)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] && str[i + 1] == 'n')
			ft_echo_bs(str, &i);
		else
		{
			if (str[i] == 'n' && ft_is_bs(i + len + 1))
			{
				ft_putchar('\n');
				i++;
			}
			else if (str[i])
			{
				ft_putchar(str[i]);
				i++;
			}
		}
	}
}

void	ft_echo(char **input)
{
	int		i;

	i = 1;
	while (input[i])
	{
		ft_print(input[i], (int)(ft_strlen(input[0])));
		if (input[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
