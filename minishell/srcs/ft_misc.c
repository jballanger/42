/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:18:44 by jballang          #+#    #+#             */
/*   Updated: 2017/03/13 13:11:18 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_leave(char *message)
{
	ft_putendl(message);
	exit(0);
}

int		is_env(char *str)
{
	if (ft_strcmp(str, "env") == 0 ||\
		ft_strcmp(str, "/usr/bin/env") == 0)
		return (1);
	return (0);
}

int		ft_length(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*arrtostr(char **input)
{
	int		i;
	int		total;
	char	*string;

	i = 0;
	total = 0;
	while (input[i])
		total += ft_strlen(input[i++]);
	if (!(string = (char*)malloc(sizeof(char) * total + 1)))
		ft_leave("malloc error: ft_misc.c:49");
	ft_bzero(string, total + 1);
	i = 0;
	while (input[i])
	{
		string = ft_strcat(string, input[i++]);
		if (input[i])
			string = ft_strcat(string, " ");
	}
	return (string);
}

int		is_blank(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
