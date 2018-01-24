/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:50:44 by jballang          #+#    #+#             */
/*   Updated: 2017/02/01 11:37:57 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lsl_call(t_dir *dir, t_files *files, int max[], char *opt)
{
	if (dir->files->type == -42)
	{
		ft_opendirerr(dir->files->name, dir->files->error);
		if (dir->next)
			ft_putchar('\n');
	}
	else
	{
		opt_l_first(files, dir, max, opt);
		opt_l_second(max, files, dir);
	}
}
