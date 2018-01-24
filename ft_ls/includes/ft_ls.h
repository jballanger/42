/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 14:27:01 by jballang          #+#    #+#             */
/*   Updated: 2017/02/02 11:00:22 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>

typedef struct		s_files
{
	char			name[256];
	char			*error;
	int				type;
	struct stat		*stat;
	struct s_files	*next;
}					t_files;

typedef struct		s_dir
{
	char			name[256];
	struct s_files	*files;
	struct s_dir	*next;
}					t_dir;

void				ft_parser\
					(int argc, char **argv, char **opt, t_list **directory);
t_files				*ft_filesnew(char name[], int type, char *error);
void				ft_filesadd(t_files **alst, t_files *new);
void				ft_filespush(t_files **alst, t_files *new);
int					ft_filesrange(t_files *lst);
t_dir				*ft_dirnew(char *name, t_files *files);
void				ft_dirpush(t_dir **alst, t_dir *new);
int					ft_dirrange(t_dir **dir);
int					ft_rdirrange(t_dir **dir);
void				ft_opt(char *opt, t_dir *dir);
void				ft_read(char *opt, t_list *directory);
void				ft_ls(char *opt, t_dir *dir, t_files *f);
void				sort_files(t_dir **dir);
void				sort_time(t_dir **dir);
void				ft_statsadd(char *dirname, t_files **file);
void				ft_statswap(t_files **file1, t_files **file2);
int					is_validopt(char *opt);
void				leave(char c);
void				malleave(char *str);
void				ft_putparam(char *p1, char *p2, char *p3, char *p4);
void				ft_opendirerr(char *dirname, char *error);
int					get_max_size(t_files *files, char *opt);
int					get_max_uname(t_files *files, char *opt);
int					get_max_grp(t_files *files, char *opt);
int					get_max_link(t_files *files, char *opt);
int					get_max_dev(t_files *files, char *opt);
char				*ft_dirjoin(char *path, char *file);
char				*ft_tsmp(time_t tsmp);
void				opt_rev(t_dir **dir);
void				opt_r(t_dir *tmp, char *opt);
void				ft_lsl(char *opt, t_dir *dir, t_files *f);
void				display_right(mode_t rights);
void				display_acl_xattr(t_files *files, char *dirname);
int					get_blocks(t_files **files, char *opt);
int					check_dev(t_dir **dir);
void				ft_putcn(int order, char *str, int nb, int nl);
int					ft_getdirrange(t_dir *dir, char *opt);
char				*get_uname(uid_t uid);
char				*get_grp(gid_t gid);
void				ft_islink(t_files *files, t_dir *dir);
int					ft_count_files(t_dir **dir, char *opt);
void				lsl_call(t_dir *dir, t_files *files, int max[], char *opt);
void				opt_l_first\
					(t_files *files, t_dir *dir, int max[], char *opt);
void				opt_l_second(int max[], t_files *files, t_dir *dir);

#endif
