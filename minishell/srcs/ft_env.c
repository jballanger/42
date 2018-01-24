/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:54:37 by jballang          #+#    #+#             */
/*   Updated: 2017/03/06 14:55:32 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_newenv(char **newenv)
{
	int		x;

	x = 0;
	while (newenv[x])
	{
		ft_putendl(newenv[x]);
		x++;
	}
	ft_arrdel(newenv);
}

void	do_env(char **input, int i)
{
	char	**newenv;
	char	**tmpenv;

	newenv = ft_cpyenv();
	while (input[i])
	{
		if (ft_strchr(input[i], '='))
		{
			tmpenv = env_add(newenv, input[i]);
			if (newenv && ft_length(newenv) > 0)
				ft_arrdel(newenv);
			newenv = tmpenv;
		}
		else if (is_env(input[i - 1]) && input[i][0] == '-')
			i = ft_env_opt(&newenv, input, i);
		else if (!is_env(input[i]))
		{
			i = env_cmd(&input[i], newenv);
			break ;
		}
		i++;
	}
	if (i != -42 && newenv)
		display_newenv(newenv);
}

char	invalid_opt(char **input, int i, int j)
{
	while (input[i])
	{
		j = 0;
		if (ft_strchr(input[i], '-'))
		{
			while (input[i][j])
			{
				if (input[i][j] == '-' && ft_strcmp(input[i - 1], "env") == 0)
				{
					j++;
					while (input[i][j] != '\0' && input[i][j] != ' ')
					{
						if (input[i][j] != 'i' && input[i][j] != 'u')
							return (input[i][j]);
						j++;
					}
				}
				if (input[i][j] != '\0')
					j++;
			}
		}
		i++;
	}
	return (0);
}

void	display_env(void)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i])
		ft_putendl(environ[i++]);
}

void	ft_env(char **input)
{
	int		length;
	int		i;
	int		j;
	int		tmp;

	length = ft_length(input);
	i = 0;
	j = 0;
	tmp = 1;
	if (length == 1 || (length == 2 && input[1][0] == '\0'))
		display_env();
	else
	{
		if (!invalid_opt(input, i, j))
			do_env(input, tmp);
		else
		{
			ft_putstr("env: illegal option -- ");
			ft_putchar(invalid_opt(input, i, j));
			ft_putendl(\
			"\nusage: env [-i] [name=value ...] [utility [argument ...]]");
		}
	}
}
