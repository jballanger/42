/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quoted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:51:35 by jballang          #+#    #+#             */
/*   Updated: 2017/05/15 10:05:26 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strpos(char *str, char c, int start)
{
	int		i;

	i = start;
	if (c == '>')
	{
		if (!ft_strchr(&str[i], '>') && !ft_strchr(&str[i], '<'))
			return (-1);
		while (str[i] && str[i] != '>' && str[i] != '<')
			i++;
	}
	else
	{
		if (!ft_strchr(&str[i], c))
			return (-1);
		while ((str[i] && str[i] != c) || (str[i] == c && str[i - 1] == '\\'))
			i++;
	}
	return (i);
}

int		ft_isquote(int pos)
{
	int		i;

	i = 0;
	if (g_term.quotes)
	{
		while (g_term.quotes[i] > -1)
		{
			if (g_term.quotes[i] < pos && g_term.quotes[i + 1] > pos)
				return (1);
			i += 2;
		}
	}
	return (0);
}

int		ft_is_redir(void)
{
	int		pos;
	int		old;
	char	*tmp;

	old = 0;
	tmp = ft_strdup(g_term.cmd);
	while ((pos = ft_strpos(tmp, '>', old)) > -1)
	{
		if (!ft_isquote(pos))
		{
			free(tmp);
			return (1);
		}
		old = pos + 1;
	}
	free(tmp);
	return (0);
}

int		ft_ispipe(void)
{
	int		pos;
	int		old;
	char	*tmp;

	tmp = ft_strdup(g_term.cmd);
	old = 0;
	while ((pos = ft_strpos(tmp, '|', old)) > -1)
	{
		if (!ft_isquote(pos))
		{
			free(tmp);
			return (1);
		}
		old = pos + 1;
	}
	free(tmp);
	return (0);
}
