/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_misc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:36:44 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 13:54:00 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_openfile_error(char *file, int err)
{
	char	*error;

	if (err == -1)
	{
		error = ft_strjoin("21sh: no such file or directory ", file);
		ft_putendl_fd(error, 2);
		free(error);
	}
}

int		is_single_right(char *cmd)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strdup(ft_strchr(cmd, '>'));
	while (tmp[i] && is_space_tab(tmp[i]))
		i++;
	if (tmp[i] == '>')
	{
		free(tmp);
		return (0);
	}
	while (ft_isvalid(tmp[i]))
		i++;
	free(tmp);
	if (i == 1)
		return (0);
	return (1);
}

int		is_double_right(char *cmd)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strdup(ft_strchr(cmd, '>'));
	if (tmp[i] != '>' || tmp[i - 1] != '>')
	{
		free(tmp);
		return (0);
	}
	i++;
	while (tmp[i] && is_space_tab(tmp[i]))
		i++;
	while (ft_isvalid(tmp[i]))
		i++;
	free(tmp);
	if (i == 2)
		return (0);
	return (1);
}

int		is_single_left(char *cmd)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strdup(ft_strchr(cmd, '<'));
	if (tmp[i] == '<')
	{
		free(tmp);
		return (0);
	}
	while (tmp[i] && is_space_tab(tmp[i]))
		i++;
	while (ft_isvalid(tmp[i]))
		i++;
	if (!is_space_tab(tmp[i]) && tmp[i])
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (i == 1)
		return (0);
	return (1);
}

int		is_double_left(char *cmd)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strdup(ft_strchr(cmd, '<'));
	if (tmp[i] != '<' || tmp[i - 1] != '<')
	{
		free(tmp);
		return (0);
	}
	i++;
	while (tmp[i] && is_space_tab(tmp[i]))
		i++;
	while (ft_isvalid(tmp[i]))
		i++;
	if (!is_space_tab(tmp[i]) && tmp[i])
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (i == 2)
		return (0);
	return (1);
}
