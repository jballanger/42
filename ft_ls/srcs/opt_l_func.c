/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:58:15 by jballang          #+#    #+#             */
/*   Updated: 2017/01/31 12:59:18 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_right(mode_t rights)
{
	if (S_ISDIR(rights))
		ft_putchar('d');
	else if (S_ISCHR(rights))
		ft_putchar('c');
	else if (S_ISBLK(rights))
		ft_putchar('b');
	else if (S_ISFIFO(rights))
		ft_putchar('p');
	else if (S_ISLNK(rights))
		ft_putchar('l');
	else if (S_ISSOCK(rights))
		ft_putchar('s');
	else
		ft_putchar('-');
	(rights & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(rights & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	(rights & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(rights & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(rights & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	(rights & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(rights & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(rights & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	(rights & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
}

void	display_acl_xattr(t_files *files, char *dirname)
{
	size_t	xattr;

	xattr = listxattr(ft_dirjoin(dirname, files->name)\
		, NULL, 0, XATTR_NOFOLLOW);
	if (acl_get_file(files->name, ACL_TYPE_EXTENDED))
		ft_putchar('+');
	else if ((int)xattr > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
}

void	ft_islink(t_files *files, t_dir *dir)
{
	char	buff[4096];

	ft_bzero(buff, 4096);
	if (S_ISLNK(files->stat->st_mode))
	{
		if (readlink(ft_dirjoin(dir->name, files->name), buff, 4096) != -1)
			ft_putparam(" -> ", buff, NULL, NULL);
		else
			ft_putparam(" -> ", strerror(errno), NULL, NULL);
	}
}

int		check_dev(t_dir **dir)
{
	t_dir	*tmp;
	t_files *tmp_files;

	tmp = *dir;
	tmp_files = tmp->files;
	while (tmp_files)
	{
		if (S_ISCHR(tmp_files->stat->st_mode) ||\
			S_ISBLK(tmp_files->stat->st_mode))
			return (1);
		tmp_files = tmp_files->next;
	}
	return (0);
}

int		ft_getdirrange(t_dir *dir, char *opt)
{
	int	dirrange;

	dirrange = ft_dirrange(&dir);
	if (opt && ft_strchr(opt, 'R'))
		dirrange = 0;
	return (dirrange);
}
