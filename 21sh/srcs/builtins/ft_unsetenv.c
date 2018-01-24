/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:44:42 by jballang          #+#    #+#             */
/*   Updated: 2017/05/30 13:09:14 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reorder(int key)
{
	int			i;
	char		tmp[4096];
	extern char	**environ;

	i = key;
	while (environ[i + 1])
	{
		ft_bzero(tmp, 4096);
		ft_strcpy(tmp, environ[i + 1]);
		free(environ[i]);
		environ[i] = ft_strnew(ft_strlen(tmp));
		ft_strcpy(environ[i], tmp);
		environ[i][ft_strlen(tmp)] = '\0';
		i++;
	}
	free(environ[i]);
	environ[i] = NULL;
}

void	free_null(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_unsetenv(char **input)
{
	extern char		**environ;
	int				key;
	unsigned long	length;
	int				i;

	length = ft_length(input);
	i = 1;
	if (length < 2)
		ft_putendl("unsetenv: Too few arguments.");
	else
	{
		while (input[i])
		{
			key = get_envkey(input[i]);
			if (key != -1)
			{
				if (environ[key + 1])
					ft_reorder(key);
				else
					free_null(&environ[key]);
			}
			i++;
		}
	}
}
