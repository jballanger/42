/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:00:23 by jballang          #+#    #+#             */
/*   Updated: 2017/02/02 10:58:56 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files	*reverse(t_files *files)
{
	t_files	*prev;
	t_files	*next;

	prev = NULL;
	while (files)
	{
		next = files->next;
		files->next = prev;
		prev = files;
		files = next;
	}
	return (prev);
}

void	opt_rev(t_dir **dir)
{
	t_dir		*tmp;
	t_files		*files;

	tmp = *dir;
	while (tmp)
	{
		files = tmp->files;
		tmp->files = reverse(files);
		tmp = tmp->next;
	}
}
