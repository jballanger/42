/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:43:35 by jballang          #+#    #+#             */
/*   Updated: 2017/03/06 12:29:55 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		separator_count(char *str)
{
	int		separator;
	int		i;

	separator = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ';')
			separator++;
		i++;
	}
	return (separator);
}

char	**ft_separator(char *line)
{
	int		i;
	int		start;
	int		j;
	char	**res;
	char	*tmp;

	i = 0;
	start = 0;
	j = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (separator_count(line) + 2))))
		ft_leave("malloc error : ft_separator:37");
	while (line[i])
	{
		start = i;
		while (line[i] && line[i] != ';')
			i++;
		tmp = ft_strsub(line, start, (i - start));
		res[j++] = ft_strdup(tmp);
		free(tmp);
		if (line[i])
			i++;
	}
	res[j] = NULL;
	return (res);
}
