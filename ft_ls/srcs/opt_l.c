/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:42:04 by jballang          #+#    #+#             */
/*   Updated: 2017/02/01 16:19:22 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_max(int *max, t_dir *dir, char *opt)
{
	max[0] = 0;
	max[1] = get_max_link(dir->files, opt);
	max[2] = get_max_uname(dir->files, opt);
	max[3] = get_max_grp(dir->files, opt);
	max[4] = get_max_size(dir->files, opt);
	max[5] = get_max_dev(dir->files, opt);
}

void	opt_l_first(t_files *files, t_dir *dir, int max[], char *opt)
{
	display_right(files->stat->st_mode);
	display_acl_xattr(files, dir->name);
	max[0] = max[1] - ft_intlen(files->stat->st_nlink);
	ft_putstr(" ");
	while (max[0]-- > 0)
		ft_putstr(" ");
	ft_putnbr(files->stat->st_nlink);
	ft_putstr(" ");
	if (!ft_strchr(opt, 'g'))
		ft_putparam(get_uname(files->stat->st_uid), "  ", NULL, NULL);
	max[0] = max[2] - ft_strlen(get_uname(files->stat->st_uid));
	while (max[0]-- > 0)
		ft_putstr(" ");
	ft_putstr(get_grp(files->stat->st_gid));
	max[0] = max[3] - ft_strlen(get_grp(files->stat->st_gid));
	while (max[0]-- > 0)
		ft_putstr(" ");
	max[0] = max[4] - ft_intlen(files->stat->st_size);
	if (check_dev(&dir))
		max[0] -= ft_intlen(major(files->stat->st_rdev));
	ft_putstr("  ");
	while (max[0]-- > 0)
		ft_putstr(" ");
}

void	opt_l_second(int max[], t_files *files, t_dir *dir)
{
	max[0] = max[5] - ft_intlen(minor(files->stat->st_rdev));
	if (S_ISCHR(files->stat->st_mode) || S_ISBLK(files->stat->st_mode))
	{
		ft_putcn(2, ", ", major(files->stat->st_rdev), 0);
		while (max[0]-- > 0)
			ft_putstr(" ");
		ft_putnbr(minor(files->stat->st_rdev));
	}
	else
	{
		if (check_dev(&dir))
			max[0] += 3;
		while (max[0]-- > 0)
			ft_putstr(" ");
		ft_putnbr(files->stat->st_size);
	}
	ft_putparam(" ", ft_tsmp(files->stat->st_mtime), " ", files->name);
	ft_islink(files, dir);
	ft_putchar('\n');
}

int		ft_nl(int dirrange, t_dir *dir)
{
	if ((dirrange > 1 && dir->next) && dir->files->type != -42)
		ft_putchar('\n');
	return (1);
}

void	ft_lsl(char *opt, t_dir *dir, t_files *f)
{
	int				max[6];
	int				dirrange;
	static int		opt_r = 0;

	dirrange = ft_getdirrange(dir, opt);
	while (dir)
	{
		if (opt && ft_strchr(opt, 'R') && opt_r > 0)
			ft_putchar('\n');
		f = dir->files;
		ft_max(&max[0], dir, opt);
		if ((dirrange > 1 || opt_r > 0) && dir->files->type != -42)
			ft_putparam(dir->name, ":\n", NULL, NULL);
		if (dir->files->type != -42 && ft_count_files(&dir, opt))
			ft_putcn(1, "total ", get_blocks(&f, opt), 1);
		while (f)
		{
			if ((ft_strchr(opt, 'a') || ft_strchr(opt, 'f')) ? (1 == 1) :\
				(f->error || ((f->name[0] != '.') && ft_strlen(f->name) > 0)))
				lsl_call(dir, f, max, opt);
			f = f->next;
		}
		opt_r += ft_nl(dirrange, dir);
		dir = dir->next;
	}
}
