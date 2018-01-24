/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:38:29 by jballang          #+#    #+#             */
/*   Updated: 2017/06/09 10:32:27 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_getfd(char *cmd, char **tmp)
{
	int		ret;

	if (ft_strlen(cmd) > 2 && ft_isdigit(cmd[ft_strlen(cmd) - 1]))
	{
		*tmp = ft_strsub(cmd, 0, ft_strlen(cmd) - 1);
		ret = cmd[ft_strlen(cmd) - 1] - 48;
		if (ret > 2)
		{
			ft_putstr_fd("21sh: ", 2);
			ft_putnbr_fd(ret, 2);
			ft_putendl_fd(": Bad file descriptor", 2);
			return (-1);
		}
		return (ret);
	}
	else
	{
		*tmp = ft_strdup(cmd);
		return (1);
	}
}

int		ft_getout(char **redirect, int single)
{
	char	*tmp;

	tmp = *redirect;
	if (tmp[0] == '&')
	{
		if (tmp[1])
		{
			if (tmp[1] > 47 && tmp[1] < 51)
				return (tmp[1] - 48);
			else if (tmp[1] == '-')
			{
				free(*redirect);
				*redirect = ft_strdup("/dev/null");
				tmp = *redirect;
				return (ft_openfile(tmp, single));
			}
			else
				return (1);
		}
		else
			return (ft_openfile(tmp, single));
	}
	else
		return (ft_openfile(tmp, single));
}

void	ft_redirect_right(char *cmd, char *redirect, char **newenv, int single)
{
	int		file;
	int		out;
	int		fd;
	char	*tmp;

	fd = ft_getfd(cmd, &tmp);
	file = ft_getout(&redirect, single);
	if (file == -1 || fd == -1)
		ft_openfile_error(redirect, file);
	else
	{
		if ((out = dup(fd)) == -1)
			ft_putendl_fd("21sh: error while dup(fd)", 2);
		if (dup2(file, fd) == -1)
			ft_putendl_fd("21sh: error while dup2(file, fd)", 2);
		lexer(tmp, newenv);
		if (file != 1 && file != 2 && close(file) == -1)
			ft_putendl_fd("21sh: error while closing file", 2);
		if (dup2(out, fd) == -1)
			ft_putendl_fd("21sh: error while dup2(out, fd)", 2);
		if (close(out) == -1)
			ft_putendl_fd("21sh: error while closing out", 2);
	}
	free(tmp);
	free(redirect);
}
