/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:06:58 by jballang          #+#    #+#             */
/*   Updated: 2017/02/02 10:48:42 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_stats(t_dir **dir)
{
	t_dir		*tmp;
	t_files		*tmp_files;
	char		*path;
	char		tmp_name[4096];

	tmp = *dir;
	while (tmp)
	{
		tmp_files = tmp->files;
		while (tmp_files)
		{
			ft_strcpy(tmp_name, tmp->name);
			if (!(path = ft_strnew(\
				(ft_strlen(tmp->name) + ft_strlen(tmp_files->name) + 1))))
				malleave("opt.c:31");
			ft_strcpy(path, tmp_name);
			if (tmp_name[ft_strlen(tmp_name) - 1] != '/')
				ft_strncat(path, "/", 1);
			ft_strncat(path, tmp_files->name, ft_strlen(tmp_files->name));
			ft_statsadd(path, &tmp_files);
			ft_bzero(path, (ft_strlen(path) + 1));
			tmp_files = tmp_files->next;
		}
		tmp = tmp->next;
	}
}

void	ft_opt(char *opt, t_dir *dir)
{
	t_dir	*tmp;
	t_files	*tmp_files;

	tmp = dir;
	tmp_files = tmp->files;
	get_stats(&dir);
	if (ft_strchr(opt, 't'))
		sort_time(&dir);
	if (ft_strchr(opt, 'r'))
		opt_rev(&dir);
	if (ft_strchr(opt, 'l') || ft_strchr(opt, 'g'))
		ft_lsl(opt, tmp, tmp_files);
	else
		ft_ls(opt, tmp, tmp_files);
	if (ft_strchr(opt, 'R'))
		opt_r(dir, opt);
}
