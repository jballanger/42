/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 09:23:51 by jballang          #+#    #+#             */
/*   Updated: 2017/05/30 14:26:09 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_new_heredoc(char *cmd)
{
	char	**hd;

	hd = (char**)malloc(sizeof(char*) * 2);
	hd[0] = ft_strdup(cmd);
	hd[1] = NULL;
	return (hd);
}

char	**ft_modify_heredoc(char **curr, char *cmd)
{
	unsigned long	len;
	unsigned long	i;
	char			**hd;

	len = ft_length(curr);
	i = 0;
	hd = (char**)malloc(sizeof(char*) * (len + 2));
	while (i < len)
	{
		hd[i] = ft_strdup(curr[i]);
		i++;
	}
	hd[i++] = ft_strdup(cmd);
	hd[i] = NULL;
	return (hd);
}

char	*ft_arrcpy(char **arr, int len)
{
	int		i;
	int		j;
	int		c;
	char	*str;

	i = 0;
	c = 0;
	str = ft_strnew((size_t)len + 1);
	while (arr && arr[i])
	{
		j = 0;
		while (arr[i][j])
			str[c++] = arr[i][j++];
		if (arr[i + 1])
		{
			str[c++] = '\\';
			str[c++] = 'n';
		}
		i++;
	}
	str[c++] = '"';
	str[c++] = '|';
	str[c] = '\0';
	return (str);
}
