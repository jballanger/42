/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:43:28 by jballang          #+#    #+#             */
/*   Updated: 2017/06/06 11:38:25 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_count(char **arr)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	while (arr && arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			j++;
			c++;
		}
		c += 2;
		i++;
	}
	return (c);
}

char	**ft_joincmd(char *cmd1, char *cmd2)
{
	char	**ret;

	ret = (char**)malloc(sizeof(char*) * (2));
	ret[0] = ft_strdup(cmd1);
	ret[1] = ft_strdup(cmd2);
	return (ret);
}

char	*ft_here_merge(char *first)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(first, g_term.heredoc_cmd[0]);
	tmp2 = ft_strjoin(tmp, g_term.heredoc_cmd[1]);
	free(tmp);
	return (tmp2);
}

void	ft_here_clean(void)
{
	int		i;

	i = 0;
	while (g_term.heredoc && g_term.heredoc[i])
	{
		free(g_term.heredoc[i]);
		g_term.heredoc[i] = NULL;
		i++;
	}
	free(g_term.heredoc);
	g_term.heredoc = NULL;
}

void	ft_heresafeclear(t_term *term)
{
	if (term->heredoc_end)
		free(term->heredoc_end);
	if (term->heredoc_cmd)
	{
		if (term->heredoc_cmd[0])
			free(term->heredoc_cmd[0]);
		if (term->heredoc_cmd[1])
			free(term->heredoc_cmd[1]);
		free(term->heredoc_cmd);
	}
	if (term->heredoc)
		ft_here_clean();
}
