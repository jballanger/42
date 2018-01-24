/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:08:13 by jballang          #+#    #+#             */
/*   Updated: 2017/03/20 11:28:43 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include <stdlib.h>

void				minishell(char *buff, pid_t father, char **newenv);
void				minishell_loop(char *buff, char **newenv);
int					ft_length(char **arr);
char				**parser(char *buff, char **path, char **newenv);
int					is_builtins(char *cmd);
void				builtins(char *buff, char **newenv);
void				ft_cd(char **input, char **newenv);
void				ft_echo(char **input);
void				ft_setenv(char **input);
void				ft_unsetenv(char **input);
int					get_envkey(char *key);
char				*get_key(char *str);
char				*get_envvar(char *var);
int					get_newenvkey(char **newenv, char *key);
void				ft_env(char **input);
void				display_env(void);
char				**ft_cpyenv(void);
char				**env_add(char	**currenv, char *new);
char				**env_remove(char ***currenv, char *toremove);
void				env_reset(char ***newenv);
int					env_cmd(char **input, char **newenv);
void				ft_arrdel(char **arr);
int					is_env(char *str);
void				ft_leave(char *message);
char				*arrtostr(char **input);
void				ft_newreorder(char ***newenv, int key);
char				**env_add(char **currenv, char *new);
char				**env_replace(char **currenv, char *new, int key);
char				**ft_separator(char *line);
int					is_blank(char *str);
void				env_preadd(char ***env, char *input);
int					ft_env_opt(char ***env, char **input, int i);
int					is_exe(char *file, int leave);

#endif
