/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stats.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:21:39 by jballang          #+#    #+#             */
/*   Updated: 2017/01/31 14:56:28 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_statsadd(char *dirname, t_files **file)
{
	t_files		*tmp;

	tmp = *file;
	if (!(tmp->stat = malloc(sizeof(struct stat))))
		malleave("ft_stats.c:21");
	lstat(dirname, tmp->stat);
}

void	ft_statswap(t_files **file1, t_files **file2)
{
	struct stat	*stat1;
	struct stat	*stat2;
	t_files		*tmp1;
	t_files		*tmp2;

	tmp1 = *file1;
	tmp2 = *file2;
	stat1 = tmp1->stat;
	stat2 = tmp2->stat;
	tmp1->stat = stat2;
	tmp2->stat = stat1;
}
