/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:32:58 by jballang          #+#    #+#             */
/*   Updated: 2017/03/13 13:10:47 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_newenvkey(char **newenv, char *key)
{
	int			i;
	char		tmp[4096];

	i = 0;
	ft_bzero(tmp, 4096);
	ft_strcpy(tmp, key);
	tmp[ft_strlen(tmp) + 1] = '\0';
	tmp[ft_strlen(tmp)] = '=';
	while (newenv[i])
	{
		if (ft_strncmp(newenv[i], tmp, ft_strlen(tmp)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_key(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str))))
		ft_leave("malloc error: ft_get.c:40");
	ft_strcpy(tmp, str);
	while (tmp[i] != '=')
		i++;
	tmp[i] = '\0';
	return (tmp);
}

int		ft_env_opt(char ***env, char **input, int i)
{
	if (ft_strchr(input[i], 'u') && input[i + 1])
		env_remove(env, input[i + 1]);
	else if (ft_strchr(input[i], 'u'))
		ft_leave("env: option requires an argument -- u");
	if (ft_strchr(input[i], 'i'))
		env_reset(env);
	if (ft_strchr(input[i], 'u') && input[i + 1])
		i++;
	return (i);
}
