/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:32:52 by jballang          #+#    #+#             */
/*   Updated: 2017/06/09 10:32:53 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_get_file(char *cmd, size_t i, char c)
{
	char	*file;
	char	*tmp;
	size_t	start;
	size_t	len;

	if (ft_strchr(cmd, c))
	{
		tmp = ft_strdup(ft_strchr(cmd, c));
		len = 0;
		while (tmp[i] && !ft_isvalid(tmp[i]))
			i++;
		start = i;
		while (tmp[i] && tmp[i] != c && tmp[i] != ' ')
		{
			i++;
			len++;
		}
		file = ft_strsub(tmp, (unsigned int)start, len);
		free(tmp);
	}
	else
		file = NULL;
	return (file);
}

unsigned long	ft_get_newcmd_len(char *cmd, int flag, char c)
{
	int				i;
	unsigned long	len;

	i = 0;
	len = 0;
	while (cmd[i] && cmd[i++] != c)
		len++;
	while (cmd[i] && !ft_isvalid(cmd[i]))
		i++;
	while (cmd[i] && cmd[i] != c && cmd[i] != ' ')
		i++;
	if (flag)
	{
		while (cmd[i++])
			len++;
	}
	else
	{
		while (cmd[i] && cmd[i++] != c)
			len++;
	}
	len++;
	return (len);
}

char			*ft_get_newcmd(char *cmd, int flag, char c)
{
	char			*newcmd;
	int				i;
	int				j;
	unsigned long	len;

	i = 0;
	j = 0;
	len = ft_get_newcmd_len(cmd, flag, c);
	newcmd = (char*)malloc(sizeof(char) * len);
	while (cmd[i] && cmd[i] != c)
		newcmd[j++] = cmd[i++];
	while (cmd[i] && !ft_isvalid(cmd[i]))
		i++;
	while (cmd[i] && cmd[i] != c && cmd[i] != ' ')
		i++;
	while (flag && cmd[i])
		newcmd[j++] = cmd[i++];
	while (!flag && cmd[i] && cmd[i] != c)
		newcmd[j++] = cmd[i++];
	newcmd[j] = '\0';
	return (newcmd);
}

void			ft_redir_rec(char *cmd, char **newenv, t_list **files, int s)
{
	char	*nextcmd;
	char	*newcmd;
	t_list	*tmp;

	nextcmd = ft_get_newcmd(cmd, 1, '>');
	newcmd = ft_get_newcmd(cmd, 0, '>');
	tmp = *files;
	ft_create_files(files);
	if (tmp)
		ft_redirect_right(newcmd, tmp->content, newenv, s);
	if (tmp && tmp->next)
	{
		g_term.piping = 1;
		minishell_loop(nextcmd, newenv, 0);
		g_term.piping = 0;
	}
	ft_lstdel(files, ft_del);
	free(newcmd);
	free(nextcmd);
}

void			ft_single_right(char *cmd, char **newenv)
{
	char	*file;
	t_list	*files;
	char	*cmdfile;
	char	*tmp;

	file = ft_get_file(cmd, 1, '>');
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
			file = ft_get_file(cmdfile, 1, '>');
			tmp = ft_get_newcmd(cmdfile, 1, '>');
			free(cmdfile);
			cmdfile = tmp;
		}
	}
	free(cmdfile);
	ft_redir_rec(cmd, newenv, &files, 1);
}
