/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:40:21 by jballang          #+#    #+#             */
/*   Updated: 2017/06/01 14:16:24 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cq_inquote(char *str, int i, char quote)
{
	int		j;
	int		c;
	int		m;
	char	oquote;

	j = 0;
	c = 0;
	m = 0;
	if (quote == '\'')
		oquote = '"';
	else
		oquote = '\'';
	while (str[j])
	{
		if (j == i && c % 2 == 1 && m % 2 == 0)
			return (1);
		else if (j == i)
			return (0);
		if (str[j] == oquote)
			c++;
		if (str[j] == quote)
			m++;
		j++;
	}
	return (0);
}

int		ft_count_quote(char *str, char quote)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == quote && !ft_cq_inquote(str, i, quote))
		{
			if (i > 0)
			{
				if (str[i - 1] != '\\')
					n++;
			}
			else
				n++;
		}
		i++;
	}
	return (n);
}

int		ft_quote_checker(char *cmd)
{
	int		squote;
	int		dquote;

	squote = ft_count_quote(cmd, '\'');
	dquote = ft_count_quote(cmd, '"');
	if (squote % 2 != 0)
	{
		ft_putendl_fd("unmatched '", 2);
		return (0);
	}
	if (dquote % 2 != 0)
	{
		ft_putendl_fd("unmatched \"", 2);
		return (0);
	}
	return (1);
}

void	ft_order_quotes(t_term *term)
{
	int		i;
	int		tmp;
	int		bubble;

	bubble = 1;
	i = 0;
	while (bubble == 1)
	{
		bubble = 0;
		i = 0;
		while (term->quotes[i + 1] > -1)
		{
			if (term->quotes[i] > term->quotes[i + 1])
			{
				bubble = 1;
				tmp = term->quotes[i + 1];
				term->quotes[i + 1] = term->quotes[i];
				term->quotes[i] = tmp;
			}
			i++;
		}
	}
}

void	ft_remove_quotes(char **cmd)
{
	int		i;
	int		pos;
	int		dec;
	char	*tmp;

	i = 0;
	pos = 0;
	dec = 0;
	tmp = *cmd;
	while (g_term.quotes[i] > -1)
	{
		pos = g_term.quotes[i] - dec;
		while (tmp[pos + 1])
		{
			tmp[pos] = tmp[pos + 1];
			pos++;
		}
		i++;
		dec++;
	}
	if (i > 0)
		tmp[pos - (dec - 1)] = '\0';
}
