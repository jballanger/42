/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 14:20:13 by jballang          #+#    #+#             */
/*   Updated: 2017/02/01 14:25:25 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *opt, t_dir *dir, t_files *f)
{
	int			dirrange;
	static int	opt_r = 0;

	dirrange = ft_dirrange(&dir);
	if (opt && ft_strchr(opt, 'R'))
		dirrange = 0;
	while (dir)
	{
		(opt && ft_strchr(opt, 'R') && opt_r > 0) ? (ft_putchar('\n')) : (NULL);
		f = dir->files;
		if ((dirrange > 1 || opt_r > 0))
			ft_putparam(dir->name, ":\n", NULL, NULL);
		while (f && f->type != -42)
		{
			if (opt && (ft_strchr(opt, 'a') || ft_strchr(opt, 'f')))
				ft_putendl(f->name);
			else if (f->name[0] != '.')
				ft_putendl(f->name);
			f = f->next;
		}
		(f && f->error) ? ft_opendirerr(f->name, f->error) : (NULL);
		opt_r++;
		(dirrange > 1 && dir->next) ? (ft_putchar('\n')) : (NULL);
		dir = dir->next;
	}
}

void	ft_read(char *opt, t_list *directory)
{
	DIR				*odir;
	struct dirent	*current_file;
	t_files			*files;
	t_dir			*dir;

	dir = NULL;
	while (directory)
	{
		files = NULL;
		if (!(odir = opendir(directory->content)))
			files = ft_filesnew(directory->content, -42, strerror(errno));
		else
			while ((current_file = readdir(odir)))
				(files) ? (ft_filespush(&files, ft_filesnew(\
				current_file->d_name, current_file->d_type, NULL))) : (files =\
				ft_filesnew(current_file->d_name, current_file->d_type, NULL));
		if (dir)
			ft_dirpush(&dir, ft_dirnew(directory->content, files));
		else
			dir = ft_dirnew(directory->content, files);
		directory = directory->next;
	}
	if (!opt || !ft_strchr(opt, 'f'))
		sort_files(&dir);
	(opt && is_validopt(opt)) ? (ft_opt(opt, dir)) : (ft_ls(0, dir, files));
}

int		main(int argc, char **argv)
{
	char	*opt;
	t_list	*directory;

	if (argc > 1)
	{
		ft_parser(argc, argv, &opt, &directory);
		ft_read(opt, directory);
	}
	else
	{
		directory = ft_lstnew(".", 2);
		ft_read(0, directory);
	}
	return (0);
}
