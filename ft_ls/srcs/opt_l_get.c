/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:28:41 by jballang          #+#    #+#             */
/*   Updated: 2017/01/17 16:42:51 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_uname(uid_t uid)
{
	struct passwd	*user;

	user = getpwuid(uid);
	return (user->pw_name);
}

char	*get_grp(gid_t gid)
{
	struct group	*grp;

	grp = getgrgid(gid);
	return (grp->gr_name);
}

int		get_blocks(t_files **files, char *opt)
{
	t_files	*tmp;
	int		res;

	tmp = *files;
	res = 0;
	while (tmp)
	{
		if (ft_strlen(tmp->name) > 0)
		{
			if (!ft_strchr(opt, 'a') && !ft_strchr(opt, 'f'))
			{
				if (tmp->name[0] != '.')
					res += tmp->stat->st_blocks;
			}
			else
				res += tmp->stat->st_blocks;
		}
		tmp = tmp->next;
	}
	return (res);
}

int		ft_count_files(t_dir **dir, char *opt)
{
	t_dir	*tmp;
	t_files	*files;
	int		res;

	tmp = *dir;
	files = tmp->files;
	res = 0;
	while (files)
	{
		if (!ft_strchr(opt, 'a') && !ft_strchr(opt, 'g'))
		{
			if (files->name[0] != '.')
				res++;
		}
		else
			res++;
		files = files->next;
	}
	return (res);
}
