/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:08:13 by jballang          #+#    #+#             */
/*   Updated: 2017/06/09 10:28:17 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define EMALLOC "21sh: Out of memory"

# include "../libft/libft.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <stdio.h>

typedef struct			s_history
{
	char				*cmd;
	struct s_history	*next;
}						t_history;

typedef struct			s_term
{
	struct termios		t;
	struct termios		old_term;
	struct s_list		*history;
	int					*quotes;
	int					*backslash;
	char				*cmd;
	char				*cmd_temp;
	char				**heredoc;
	char				*heredoc_end;
	char				**heredoc_cmd;
	char				*copy;
	char				*dquote_prompt;
	char				*dquote_cmd;
	int					history_pos;
	int					history_len;
	int					child;
	int					heredocument;
	int					piping;
	int					copy_mode;
	int					tr;
	int					x;
	int					min_x;
	int					max_x;
	int					col;
	int					prompt_len;
	int					dquote;
}						t_term;

extern t_term			g_term;
t_term					g_term;

void					minishell(char *buff, pid_t father, char **newenv);
void					minishell_loop(char *buff, char **newenv, pid_t father);
unsigned long			ft_length(char **arr);
char					**parser\
						(char *buff, char **path, char **newenv, int pp);
int						is_builtins(char *cmd);
void					builtins(char *buff, char **newenv);
void					ft_cd(char **input, char **newenv);
void					ft_echo(char **input);
void					ft_setenv(char **input);
void					ft_unsetenv(char **input);
int						get_envkey(char *key);
char					*get_key(char *str);
char					*get_envvar(char *var);
char					*get_newenvvar(char *var, char **newenv);
int						get_newenvkey(char **newenv, char *key);
void					ft_env(char **input);
void					display_env(void);
char					**ft_cpyenv(void);
char					**env_add(char	**currenv, char *new);
char					**env_remove(char ***currenv, char *toremove);
void					env_reset(char ***newenv);
int						env_cmd(char **input, char **newenv);
void					ft_arrdel(char **arr);
int						is_env(char *str);
void					ft_leave(char *message) __attribute__((noreturn));
char					*arrtostr(char **input);
void					ft_newreorder(char ***newenv, int key);
char					**env_add(char **currenv, char *new);
char					**env_replace(char **currenv, char *new, int key);
char					**ft_separator(char *line);
int						is_blank(char *str);
void					env_preadd(char ***env, char *input);
int						ft_env_opt(char ***env, char **input, int i);
int						is_exe(char *file, int leave);
void					ft_prepath\
						(char **cmd, char **path, char **newenv, int leave);
void					ft_pipe(char **newenv);
void					ft_do_pipe(char **cmd, char **newenv);
char					**ft_splitrim(void);
void					read_input(t_term *term);
void					ft_move(t_term *term, char *buff);
void					ft_move_left(t_term *term);
void					ft_move_right(t_term *term);
void					shift_left(t_term *term, int pos);
void					shift_right(t_term *term, int pos, char replace);
int						int_putchar(int c);
void					main_loop(char *line);
void					ft_init_term(t_term *term);
void					ft_save_term(struct termios *term);
void					ft_restore_term(struct termios *term);
void					ft_history_top(t_term *term);
void					ft_history_bottom(t_term *term);
void					ft_add_history(t_term *term, char *cmd);
void					ft_clean_cmd(t_term *term);
void					ft_add_char(t_term *term, char c);
int						ft_countwordlen(char *str);
void					ft_move_word_left(t_term *term);
void					ft_move_word_right(t_term *term);
void					ft_clear_screen(t_term *term);
void					ft_eof(t_term *term);
int						is_space_tab(char c);
int						is_single_right(char *cmd);
int						is_double_right(char *cmd);
int						is_single_left(char *cmd);
int						is_double_left(char *cmd);
void					ft_redirect_checker(char *cmd, char **newenv);
void					ft_first_word(char *str);
void					ft_single_right(char *cmd, char **newenv);
void					ft_double_right(char *cmd, char **newenv);
void					ft_single_left(char *cmd, char **newenv);
void					ft_double_left(char *cmd, char **newenv);
void					int_handler(int sig);
void					lexer(char *buff, char **newnev);
void					ft_heredoc(char *here_end, char *cmd, char *cmd2);
void					heredoc_loop(char *cmd);
void					heredoc_end(void);
void					pipe_exec(char *cmd, char **newenv);
void					ft_openfile_error(char *file, int err);
int						ft_count_quote(char *str, char quote);
int						ft_quote_checker(char *cmd);
int						ft_count(char **arr);
char					*ft_arrcpy(char **arr, int len);
char					*ft_here_merge(char *first);
void					ft_here_clean(void);
void					ft_heresafeclear(t_term *term);
void					ft_read_key(char buff[6], t_term *term, int prompt);
void					ft_add_char_between(t_term *term, char c);
void					ft_return(t_term *term);
void					ft_backspace(t_term *term);
int						ft_ispipe(void);
int						ft_is_redir(void);
int						ft_strpos(char *str, char c, int start);
void					ft_mark_quote(char *cmd, int total, int i, int old);
char					**ft_strsplit_sh(char *s, char c);
int						ft_isquote(int pos);
void					ft_remove_quotes(char **cmd);
void					ft_remove_bs(char **cmd);
void					ft_mark_bs(char *cmd);
int						ft_is_bs(int i);
void					ft_alt(t_term *term, char buff[6]);
void					ft_copy(t_term *term);
void					ft_paste(t_term *term);
void					ft_add_copy(t_term *term, char c);
void					ft_remove_copy(t_term *term);
void					ft_move_line_bot(t_term *term);
void					ft_move_line_top(t_term *term);
void					ft_rewrite_cmd(t_term *term);
void					ft_reset(t_term *term);
char					**ft_new_heredoc(char *cmd);
char					**ft_modify_heredoc(char **curr, char *cmd);
void					ft_add_history(t_term *term, char *cmd);
int						ft_openfile(char *name, int single);
int						ft_dquote_checker(char *cmd);
void					dquote_loop(char *cmd);
void					ft_dquotesafeclear(t_term *term);
void					ft_columns(t_term *term);
void					ft_envvar(char **cmd);
int						ft_count_bs(char *str);
int						separator_count(char *str);
void					ft_spot(char *cmd, char **newenv);
char					*ft_path(char *cmd, char **path, int leave);
int						ft_countword(char buff[]);
char					*ft_get_first(char *str);
void					ft_tilde(char ***input, int i);
void					update_pwd(char *old, char *safedir);
void					ft_cderror(char *str);
void					do_cd(char **input, char *olddir, char *safedir);
void					do_oldcd(char **newenv, char *olddir, char *safedir);
void					ft_echo_bs(char *str, int *pos);
void					ft_print(char *str, int len);
void					display_newenv(char **newenv);
void					do_env(char **input, int i);
char					invalid_opt(char **input, int i, int j);
char					**env_cpy_add(char **currenv, char *new);
int						ft_sqbefore(char *str, int i);
char					*ft_getvar(char *cmd, int i);
char					*ft_vartranslate(char *cmd, char *var, int i);
int						check(char **input);
void					ft_reorder(int key);
void					free_null(char **str);
void					add_heredoc(char *cmd);
void					ft_here_exec(char *cmd);
void					ft_history_back(t_term *term);
void					ft_history_next(t_term *term);
void					ft_history_prev(t_term *term);
void					ft_first_copy(t_term *term, char c);
char					*ft_paste_empty(t_term *term);
char					*ft_paste_between(t_term *term);
unsigned long			ft_count_occ(char *s, char c);
unsigned long			ft_cfrom(char *s, char c, int p);
char					**ft_strsplit_sh_return(char **arr, int i);
void					ft_move_home(t_term *term);
void					ft_move_end(t_term *term);
void					ft_int_change(int *a, int *b);
void					ft_int_up(int *a, int *b);
int						child_process(char *cmd, int in, int out, int tbc);
int						prepare_child(char **cmd, int *in, int *p, int i);
void					pipe_loop(char **cmd);
void					minishell2(char *buff, char **newenv);
void					dquote_end(void);
void					dquote_add(char *cmd);
void					ft_dquote(char *cmd, char quote);
char					ft_get_firstquote(char *str);
char					ft_swap_quote(char c);
void					ft_reset_swap(char **str, int *old, char *c);
void					ft_reassign(char **str, int *old, char *c, char *cmd);
void					ft_redirect_left(char *cmd, char *file, char **newenv);
char					*ft_heredoc_parser(char *cmd, int i);
char					*ft_here_after(char *cmd, int i);
int						ft_getfd(char *cmd, char **tmp);
int						ft_getout(char **redirect, int single);
void					ft_redirect_right(char *cmd, char *redirect,\
						char **newenv, int single);
void					ft_history_pos(t_term *term);
void					ft_repos_cursor(int x, int col, int cmdlen);
void					ft_exit(char **input);
char					*ft_get_file(char *cmd, size_t i, char c);
char					*ft_get_newcmd(char *cmd, int flag, char c);
unsigned long			ft_get_newcmd_len(char *cmd, int flag, char c);
void					ft_redir_rec(char *cmd, char **newenv,\
						t_list **files, int s);
void					ft_create_files(t_list **files);
int						ft_cq_inquote(char *str, int i, char quote);
void					ft_order_quotes(t_term *term);
void					sigint_reset(t_term *term);
void					ft_move_left_copy(t_term *term, char c);
char					**ft_strsplit_builtins(char *s, char c);
void					ft_checker_right(char *cmd, char **newenv);
char					**ft_joincmd(char *cmd1, char *cmd2);

#endif
