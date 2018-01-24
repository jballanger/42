/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:53:39 by jballang          #+#    #+#             */
/*   Updated: 2017/06/07 14:45:44 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(char *old, char *safedir)
{
	char	*cwd;
	char	**input;

	if (!(input = (char**)malloc(sizeof(char*) * 4)))
		ft_leave(EMALLOC);
	if (!(cwd = (char*)malloc(sizeof(char) * 1024)))
		ft_leave(EMALLOC);
	input[0] = ft_strdup("setenv");
	if (!old)
	{
		ft_bzero(cwd, sizeof(cwd));
		if (!getcwd(cwd, 1024))
			cwd = ft_strdup(safedir);
		input[1] = ft_strdup("PWD");
		input[2] = ft_strdup(cwd);
	}
	else
	{
		input[1] = ft_strdup("OLDPWD");
		input[2] = ft_strdup(old);
	}
	input[3] = NULL;
	ft_setenv(input);
	ft_arrdel(input);
	free(cwd);
}

void	ft_cderror(char *str)
{
	struct stat	st;

	if (lstat(str, &st) == 0)
	{
		if (!(st.st_mode & S_IFDIR))
			ft_putstr("cd: not a directory: ");
		else if (!(st.st_mode & S_IRUSR) || !is_exe(str, 0))
			ft_putstr("cd: permission denied: ");
	}
	else if (open(str, O_RDONLY) == -1)
		ft_putstr("cd: no such file or directory: ");
	ft_putendl(str);
}

void	do_cd(char **input, char *olddir, char *safedir)
{
	char	*tmp;
	int		state;

	tmp = NULL;
	if (ft_length(input) == 1 || ft_strcmp(input[1], "") == 0)
		tmp = get_envvar("$HOME");
	else if (input[1][0] == '~' && get_envvar("$HOME"))
	{
		input[1] = ft_strsub(input[1], 1, ft_strlen(input[1]));
		input[1] = ft_strjoin(get_envvar("$HOME"), input[1]);
	}
	if (tmp)
	{
		state = chdir(tmp);
		free(tmp);
	}
	else
		state = chdir(input[1]);
	if (state == -1)
		ft_cderror(input[1]);
	else
	{
		update_pwd(NULL, safedir);
		update_pwd(olddir, safedir);
	}
}

void	do_oldcd(char **newenv, char *olddir, char *safedir)
{
	char	*tmp;

	if (get_newenvkey(newenv, "OLDPWD") != -1)
	{
		tmp = get_envvar("$OLDPWD");
		if (chdir(tmp) == -1)
			ft_cderror(olddir);
		else
		{
			update_pwd(NULL, safedir);
			update_pwd(olddir, safedir);
		}
		free(tmp);
	}
	else
		ft_putendl_fd("cd: OLDPWD not set", 2);
}

void	ft_cd(char **input, char **newenv)
{
	char	*olddir;
	char	*safedir;
	int		i;

	i = 0;
	if (!(olddir = (char*)malloc(sizeof(char) * 1024)))
		ft_leave(EMALLOC);
	safedir = getenv("HOME");
	if (!safedir)
	{
		safedir = ft_strdup("/");
		i = 1;
	}
	if (!(getcwd(olddir, 1024)))
		olddir = ft_strdup(safedir);
	if (ft_length(input) > 2)
		ft_putendl_fd("cd: too many arguments", 2);
	else if (input[1] && ft_strcmp(input[1], "-") == 0)
		do_oldcd(newenv, olddir, safedir);
	else
		do_cd(input, olddir, safedir);
	free(olddir);
	if (safedir && i == 1)
		free(safedir);
}
