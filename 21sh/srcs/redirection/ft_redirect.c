/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:33:22 by jballang          #+#    #+#             */
/*   Updated: 2017/06/09 10:03:02 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_openfile(char *name, int single)
{
	int		fd;

	if (single)
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else
		fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0664);
	return (fd);
}

void	ft_create_files(t_list **files)
{
	t_list	*tmp;
	int		i;

	tmp = *files;
	i = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "&", 1) != 0)
			open(tmp->content, O_CREAT, 0664);
		if (i > 0)
			free(tmp->content);
		tmp = tmp->next;
		i++;
	}
}

void	ft_checker_right(char *cmd, char **newenv)
{
	if (is_single_right(cmd))
	{
		if (g_term.piping == 1)
			ft_single_right(cmd, newenv);
		else
			ft_single_right(g_term.cmd, newenv);
	}
	else if (is_double_right(cmd))
	{
		if (g_term.piping == 1)
			ft_double_right(cmd, newenv);
		else
			ft_double_right(g_term.cmd, newenv);
	}
	else
		ft_putendl_fd("21sh: parse error near >", 2);
}

void	ft_redirect_checker(char *cmd, char **newenv)
{
	if (ft_strchr(cmd, '<') && is_double_left(cmd))
		ft_double_left(g_term.cmd, newenv);
	else if (ft_strchr(cmd, '<') && !is_single_left(cmd))
		ft_putendl_fd("21sh: parse error near <", 2);
	else if (ft_strchr(cmd, '>'))
		ft_checker_right(cmd, newenv);
	if (ft_strchr(cmd, '<') && !ft_strchr(cmd, '>'))
	{
		if (is_single_left(cmd))
			ft_single_left(cmd, newenv);
	}
}

void	ft_first_word(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isvalid(str[i]))
			*(&str[i]) = '\0';
		i++;
	}
}
