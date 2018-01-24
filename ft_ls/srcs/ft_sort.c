/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:05:40 by jballang          #+#    #+#             */
/*   Updated: 2017/02/02 10:55:18 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_errorswap(t_files **f1, t_files **f2)
{
	char	errtmp[256];
	t_files	*tmp1;
	t_files	*tmp2;

	tmp1 = *f1;
	tmp2 = *f2;
	if (tmp1->error || tmp2->error)
	{
		ft_bzero(errtmp, 256);
		if (tmp1->error)
		{
			ft_strcpy(errtmp, tmp1->error);
			if (tmp2->error)
				ft_strcpy(tmp1->error, tmp2->error);
			else
				tmp1->error = NULL;
			ft_strcpy(tmp2->error, errtmp);
		}
		else
		{
			ft_strcpy(tmp1->error, tmp2->error);
			tmp2->error = NULL;
		}
	}
}

void	ft_swapdata(t_files **f1, t_files **f2)
{
	char	name[256];
	int		type;
	t_files	*tf1;
	t_files	*tf2;

	tf1 = *f1;
	tf2 = *f2;
	ft_strcpy(name, tf2->name);
	ft_strcpy(tf2->name, tf1->name);
	ft_strcpy(tf1->name, name);
	type = tf1->type;
	tf1->type = tf2->type;
	tf2->type = type;
	ft_statswap(f1, f2);
	ft_errorswap(f1, f2);
}

void	sort_files(t_dir **dir)
{
	t_dir		*tmp;
	t_files		*tmp_files;
	int			bubble;

	tmp = *dir;
	while (tmp)
	{
		bubble = 1;
		while (bubble == 1)
		{
			tmp_files = tmp->files;
			bubble = 0;
			while (tmp_files->next)
			{
				if (ft_strcmp(tmp_files->name, tmp_files->next->name) > 0)
				{
					bubble = 1;
					ft_swapdata(&tmp_files, &tmp_files->next);
				}
				tmp_files = tmp_files->next;
			}
		}
		tmp = tmp->next;
	}
}

void	sort_time(t_dir **dir)
{
	t_dir	*tmp;
	t_files *tmp_files;
	int		bubble;

	tmp = *dir;
	while (tmp)
	{
		bubble = 1;
		while (bubble == 1)
		{
			tmp_files = tmp->files;
			bubble = 0;
			while (tmp_files->next)
			{
				if (tmp_files->stat->st_mtime < tmp_files->next->stat->st_mtime)
				{
					bubble = 1;
					ft_swapdata(&tmp_files, &tmp_files->next);
				}
				tmp_files = tmp_files->next;
			}
		}
		tmp = tmp->next;
	}
}
