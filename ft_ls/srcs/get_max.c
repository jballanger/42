/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:54:35 by jballang          #+#    #+#             */
/*   Updated: 2017/01/31 15:23:54 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_max_size(t_files *files, char *opt)
{
	t_files	*tmp;
	int		max;

	max = 0;
	tmp = files;
	while (files)
	{
		if (!ft_strchr(opt, 'a') && !ft_strchr(opt, 'f'))
		{
			if (files->name[0] != '.')
			{
				if (ft_intlen(files->stat->st_size) > max)
					max = ft_intlen(files->stat->st_size);
			}
		}
		else
		{
			if (ft_intlen(files->stat->st_size) > max)
				max = ft_intlen(files->stat->st_size);
		}
		files = files->next;
	}
	return (max);
}

int		get_max_uname(t_files *files, char *opt)
{
	struct passwd	*user;
	int				max;

	max = 0;
	while (files && files->type != -42)
	{
		user = getpwuid(files->stat->st_uid);
		if (!user)
			return (0);
		if (!ft_strchr(opt, 'a') && !ft_strchr(opt, 'f'))
		{
			if (files->name[0] != '.')
			{
				if ((int)ft_strlen(user->pw_name) > max)
					max = ft_strlen(user->pw_name);
			}
		}
		else
		{
			if ((int)ft_strlen(user->pw_name) > max)
				max = ft_strlen(user->pw_name);
		}
		files = files->next;
	}
	return (max);
}

int		get_max_grp(t_files *files, char *opt)
{
	struct group	*grp;
	int				max;

	max = 0;
	while (files && files->type != -42)
	{
		grp = getgrgid(files->stat->st_gid);
		if (!ft_strchr(opt, 'a') && !ft_strchr(opt, 'f'))
		{
			if (files->name[0] != '.')
			{
				if ((int)ft_strlen(grp->gr_name) > max)
					max = ft_strlen(grp->gr_name);
			}
		}
		else
		{
			if ((int)ft_strlen(grp->gr_name) > max)
				max = ft_strlen(grp->gr_name);
		}
		files = files->next;
	}
	return (max);
}

int		get_max_link(t_files *files, char *opt)
{
	int		max;

	max = 0;
	while (files)
	{
		if (!ft_strchr(opt, 'a') && !ft_strchr(opt, 'f'))
		{
			if (files->name[0] != '.')
			{
				if (ft_intlen(files->stat->st_nlink) > max)
					max = ft_intlen(files->stat->st_nlink);
			}
		}
		else
		{
			if (ft_intlen(files->stat->st_nlink) > max)
				max = ft_intlen(files->stat->st_nlink);
		}
		files = files->next;
	}
	return (max);
}

int		get_max_dev(t_files *files, char *opt)
{
	int		max;

	max = 0;
	while (files)
	{
		if (!ft_strchr(opt, 'a') && !ft_strchr(opt, 'f'))
		{
			if (files->name[0] != '.')
			{
				if (ft_intlen(minor(files->stat->st_rdev)) > max)
					max = ft_intlen(minor(files->stat->st_rdev));
			}
		}
		else
		{
			if (ft_intlen(minor(files->stat->st_rdev)) > max)
				max = ft_intlen(minor(files->stat->st_rdev));
		}
		files = files->next;
	}
	return (max);
}
