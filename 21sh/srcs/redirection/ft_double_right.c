/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:48:14 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 11:38:58 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_double_right(char *cmd, char **newenv)
{
	char	*file;
	t_list	*files;
	char	*cmdfile;
	char	*tmp;

	file = ft_get_file(cmd, 2, '>');
	files = NULL;
	cmdfile = ft_get_newcmd(cmd, 1, '>');
	while (file)
	{
		if (file)
		{
			if (!files)
				files = ft_lstnew(file, ft_strlen(file));
			else
				ft_lstpush(&files, ft_lstnew(file, ft_strlen(file)));
			free(file);
			file = ft_get_file(cmdfile, 2, '>');
			tmp = ft_get_newcmd(cmdfile, 1, '>');
			free(cmdfile);
			cmdfile = tmp;
		}
	}
	free(cmdfile);
	ft_redir_rec(cmd, newenv, &files, 0);
}
