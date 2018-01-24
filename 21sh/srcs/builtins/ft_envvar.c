/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:46:20 by jballang          #+#    #+#             */
/*   Updated: 2017/06/06 11:39:05 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_sqbefore(char *str, int i)
{
	int		sq;

	sq = 0;
	while (i > 0)
	{
		if (str[i] && str[i] == '\'')
			sq++;
		i--;
	}
	return (sq);
}

char	*ft_getvar(char *cmd, int i)
{
	int				sq;
	unsigned int	start;
	unsigned int	end;
	char			*var;

	sq = ft_sqbefore(cmd, i + 1);
	while (cmd[i] != '$')
	{
		if (cmd[i] == '\'')
			sq++;
		i++;
	}
	if (i > 0 && cmd[i - 1] == '\\')
		return (NULL);
	start = (unsigned int)i++;
	while (ft_isalnum(cmd[i]))
		i++;
	end = (unsigned int)i;
	while (cmd[i] && cmd[i] != '\'')
		i++;
	if ((cmd[i] && (sq % 2) == 1) || cmd[i] == '\'')
		return (NULL);
	var = ft_strsub(cmd, start, (end - start));
	return (var);
}

char	*ft_vartranslate(char *cmd, char *var, int i)
{
	int		j;
	int		k;
	char	*ret;

	j = 0;
	k = 0;
	ret = (char*)malloc(sizeof(char) * (ft_strlen(cmd) + ft_strlen(var)));
	while (j < i)
	{
		ret[j] = cmd[j];
		j++;
	}
	while (cmd[i] != '$')
		ret[j++] = cmd[i++];
	while (var[k])
		ret[j++] = var[k++];
	i++;
	while (ft_isalnum(cmd[i]))
		i++;
	while (cmd[i])
		ret[j++] = cmd[i++];
	ret[j] = '\0';
	return (ret);
}

void	ft_envvar(char **cmd)
{
	int		i;
	char	*tmp;
	char	*var;
	char	*envvar;

	i = 0;
	while (cmd[0][i] && ft_strchr(&cmd[0][i], '$'))
	{
		if ((var = ft_getvar(cmd[0], i)))
		{
			envvar = get_envvar(var);
			free(var);
			if (envvar)
			{
				tmp = ft_vartranslate(*(&cmd[0]), envvar, i);
				free(g_term.cmd);
				free(*cmd);
				*cmd = ft_strdup(tmp);
				g_term.cmd = ft_strdup(tmp);
				free(envvar);
				free(tmp);
			}
		}
		i++;
	}
}
