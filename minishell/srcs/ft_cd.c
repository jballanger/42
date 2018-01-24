/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:53:39 by jballang          #+#    #+#             */
/*   Updated: 2017/03/13 11:27:09 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(char *old)
{
	char	cwd[1024];
	char	**input;

	if (!(input = (char**)malloc(sizeof(char*) * 4)))
		ft_leave("malloc error : ft_cd.c:22");
	input[0] = ft_strdup("setenv");
	if (!old)
	{
		ft_bzero(cwd, sizeof(cwd));
		if (!getcwd(cwd, sizeof(cwd)))
			ft_leave("getcwd error : ft_cd.c:26");
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

void	do_cd(char **input, char *olddir)
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
		update_pwd(NULL);
		update_pwd(olddir);
	}
}

void	do_oldcd(char **newenv, char *olddir)
{
	char	*tmp;

	if (get_newenvkey(newenv, "OLDPWD") != -1)
	{
		tmp = get_envvar("$OLDPWD");
		if (chdir(tmp) == -1)
			ft_cderror(olddir);
		else
		{
			update_pwd(NULL);
			update_pwd(olddir);
		}
		free(tmp);
	}
	else
		ft_putendl("cd: OLDPWD not set");
}

void	ft_cd(char **input, char **newenv)
{
	char	olddir[1024];

	if (!(getcwd(olddir, sizeof(olddir))))
		ft_leave("getcwd error : ft_cd.c:93");
	if (ft_length(input) > 2)
		ft_putendl("cd: too many arguments");
	else if (input[1] && ft_strcmp(input[1], "-") == 0)
		do_oldcd(newenv, olddir);
	else
		do_cd(input, olddir);
}
