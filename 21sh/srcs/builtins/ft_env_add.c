/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:35:22 by jballang          #+#    #+#             */
/*   Updated: 2017/06/06 11:30:40 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_cpy_add(char **currenv, char *new)
{
	int				i;
	unsigned long	length;
	char			**newenv;

	i = 0;
	length = ft_length(currenv);
	if (!(newenv = (char**)malloc(sizeof(char*) * (length + 2))))
		ft_leave(EMALLOC);
	while (currenv[i])
	{
		newenv[i] = ft_strdup(currenv[i]);
		i++;
	}
	newenv[i] = ft_strdup(new);
	newenv[++i] = NULL;
	return (newenv);
}

char	**env_add(char **currenv, char *new)
{
	char	**newenv;
	char	*tmpkey;
	int		newenvkey;

	tmpkey = get_key(new);
	if (currenv)
	{
		newenvkey = get_newenvkey(currenv, tmpkey);
		if (newenvkey != -1)
		{
			free(tmpkey);
			return (env_replace(currenv, new, newenvkey));
		}
		newenv = env_cpy_add(currenv, new);
	}
	else
	{
		if (!(newenv = (char**)malloc(sizeof(char*) * 2)))
			ft_leave(EMALLOC);
		if (!(newenv[0] = ft_strdup(new)))
			ft_leave(EMALLOC);
		newenv[1] = NULL;
	}
	free(tmpkey);
	return (newenv);
}

char	**env_replace(char **currenv, char *new, int key)
{
	char	**newenv;
	int		x;

	if (!(newenv = (char**)malloc(sizeof(char*) * (ft_length(currenv) + 1))))
		ft_leave(EMALLOC);
	x = 0;
	while (currenv[x])
	{
		if (x == key)
			newenv[x] = ft_strdup(new);
		else
			newenv[x] = ft_strdup(currenv[x]);
		if (newenv[x] == NULL)
			ft_leave(EMALLOC);
		x++;
	}
	newenv[x] = NULL;
	return (newenv);
}
