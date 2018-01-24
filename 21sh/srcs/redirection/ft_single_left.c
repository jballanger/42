/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:33:46 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 13:18:58 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_single_left(char *cmd, char **newenv)
{
	char	*file;
	char	*newcmd;
	char	*cmdfile;
	char	*tmp;

	file = ft_get_file(cmd, 1, '<');
	newcmd = ft_get_newcmd(cmd, 0, '<');
	cmdfile = ft_get_newcmd(cmd, 1, '<');
	while (file)
	{
		ft_redirect_left(newcmd, file, newenv);
		file = ft_get_file(cmdfile, 1, '<');
		if (file)
		{
			tmp = ft_get_newcmd(cmdfile, 1, '<');
			free(cmdfile);
			cmdfile = tmp;
		}
	}
	free(newcmd);
	free(cmdfile);
}
