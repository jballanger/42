/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backslash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 08:34:16 by jballang          #+#    #+#             */
/*   Updated: 2017/05/15 09:05:47 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_count_bs(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if (str[i + 1])
			{
				if (str[i + 1] != '\\')
					n++;
			}
			else
				n++;
		}
		i++;
	}
	return (n);
}

int		ft_is_bs(int i)
{
	int		j;

	j = 0;
	while (g_term.backslash[j] > -1)
	{
		if (g_term.backslash[j] == i)
			return (1);
		j++;
	}
	return (0);
}

void	ft_remove_bs(char **cmd)
{
	int		i;
	int		p;
	int		dec;
	char	*tmp;

	i = 0;
	dec = 0;
	tmp = *cmd;
	while (tmp[i])
	{
		if (tmp[i] == '\\')
		{
			p = i;
			while (tmp[p + 1])
			{
				tmp[p] = tmp[p + 1];
				p++;
			}
			dec++;
			i++;
		}
		if (tmp[i])
			i++;
	}
	tmp[i - dec] = '\0';
}

void	ft_mark_bs(char *cmd)
{
	int		i;
	int		j;
	int		*backslash;

	i = 0;
	j = 0;
	backslash = (int*)malloc(sizeof(int) *\
		(unsigned int)(ft_count_bs(cmd) + 1));
	while (cmd[i])
	{
		if (cmd[i] == '\\')
		{
			if ((cmd[i - 1] && cmd[i - 1] != '\\') || (!cmd[i - 1]))
				backslash[j++] = i;
		}
		i++;
	}
	backslash[j] = -1;
	g_term.backslash = backslash;
}
