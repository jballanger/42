/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_sh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 10:29:14 by jballang          #+#    #+#             */
/*   Updated: 2017/05/30 12:26:54 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned long	ft_count_occ(char *s, char c)
{
	int				i;
	unsigned long	o;

	i = 0;
	o = 0;
	while (s[i])
	{
		if (s[i] == c)
			o++;
		i++;
	}
	return (o);
}

unsigned long	ft_cfrom(char *s, char c, int p)
{
	unsigned long	i;

	i = 0;
	while (s[p] && (s[p] != c || ft_isquote(p)))
	{
		p++;
		if (s[p] != '\'' && s[p] != '"')
			i++;
	}
	return (i);
}

char			**ft_strsplit_sh_return(char **arr, int i)
{
	arr[i] = NULL;
	return (arr);
}

int				ft_isquobs(int p)
{
	int		i;

	i = 0;
	if (ft_isquote(p))
		return (1);
	else
	{
		while (g_term.backslash[i] > -1)
		{
			if (g_term.backslash[i] == (p - 1))
				return (1);
			i++;
		}
	}
	return (0);
}

char			**ft_strsplit_sh(char *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		p;

	i = 0;
	p = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (ft_count_occ(s, c) + 2))))
		ft_leave(EMALLOC);
	while (s[p])
	{
		j = 0;
		if (!(arr[i] = (char*)malloc(sizeof(char) * (ft_cfrom(s, c, p) + 1))))
			ft_leave(EMALLOC);
		while (s[p] && (s[p] != c || ft_isquote(p)))
		{
			if ((s[p] != '\'' && s[p] != '"' && s[p] != '\\') || ft_isquobs(p))
				arr[i][j++] = s[p++];
			else
				p++;
		}
		arr[i++][j] = '\0';
		(s[p] == c) ? (p++) : (p);
	}
	return (ft_strsplit_sh_return(arr, i));
}
