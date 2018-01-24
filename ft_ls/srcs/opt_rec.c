/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:05:27 by jballang          #+#    #+#             */
/*   Updated: 2017/02/01 14:25:11 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	opt_r(t_dir *tmp, char *opt)
{
	char	*path;
	t_files *tmpf;

	while (tmp)
	{
		tmpf = tmp->files;
		while (tmpf)
		{
			if (tmpf->type == 4)
			{
				path = ft_strnew(ft_strlen(tmp->name) + ft_strlen(tmpf->name));
				ft_strcpy(path, tmp->name);
				path = ft_dirjoin(path, tmpf->name);
				if (ft_strchr(opt, 'a') && ft_strcmp(".", tmpf->name)\
					!= 0 && ft_strcmp("..", tmpf->name) != 0)
					ft_read(opt, ft_lstnew(path, ft_strlen(path)));
				else if (tmpf->name[0] != '.')
					ft_read(opt, ft_lstnew(path, ft_strlen(path)));
			}
			tmpf = tmpf->next;
		}
		tmp = tmp->next;
	}
}
