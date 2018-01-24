/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:11:57 by jballang          #+#    #+#             */
/*   Updated: 2017/05/15 09:56:04 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_get_firstquote(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (str[i]);
		i++;
	}
	return (0);
}

char	ft_swap_quote(char c)
{
	if (c == '"')
		return ('\'');
	else
		return ('"');
}

void	ft_reset_swap(char **str, int *old, char *c)
{
	free(*str);
	*old = 0;
	*c = ft_swap_quote(*c);
}

void	ft_reassign(char **str, int *old, char *c, char *cmd)
{
	free(*str);
	*str = ft_strdup(cmd);
	*old = 0;
	*c = ft_swap_quote(*c);
}

void	ft_mark_quote(char *cmd, int total, int i, int old)
{
	int		*quotes;
	char	c;
	char	*str;

	c = ft_get_firstquote(cmd);
	quotes = (int*)malloc(sizeof(int) * (unsigned long)(total + 1));
	str = ft_strdup(cmd);
	while (i < ft_count_quote(cmd, c))
	{
		quotes[i] = ft_strpos(str, c, 0) + old;
		free(str);
		str = ft_strdup(&cmd[quotes[i] + 1]);
		old = quotes[i++] + 1;
	}
	ft_reassign(&str, &old, &c, cmd);
	while (i < total)
	{
		quotes[i] = ft_strpos(str, c, 0) + old;
		free(str);
		str = ft_strdup(&cmd[quotes[i] + 1]);
		old = quotes[i++] + 1;
	}
	free(str);
	quotes[i] = -1;
	g_term.quotes = quotes;
}
