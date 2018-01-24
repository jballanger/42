NAME = 21sh
LIBFT = lft
SRC_NAME =	main/main.c\
			analyze/ft_backslash.c\
			analyze/ft_separator.c\
			analyze/lexer.c\
			analyze/parser.c\
			builtins/builtins.c\
			builtins/ft_cd.c\
			builtins/ft_echo.c\
			builtins/ft_env.c\
			builtins/ft_env_add.c\
			builtins/ft_env_func.c\
			builtins/ft_envvar.c\
			builtins/ft_exit.c\
			builtins/ft_setenv.c\
			builtins/ft_unsetenv.c\
			heredoc/ft_heredoc.c\
			heredoc/ft_heredoc_array.c\
			heredoc/ft_heredoc_misc.c\
			history/ft_history.c\
			history/ft_history_list.c\
			key/ft_alt.c\
			key/ft_copy.c\
			key/ft_ctrl.c\
			key/ft_paste.c\
			key/ft_read_input.c\
			key/ft_read_key.c\
			misc/ft_get.c\
			misc/ft_misc.c\
			misc/ft_misc2.c\
			misc/ft_shift.c\
			misc/ft_strsplit_sh.c\
			move/ft_move.c\
			move/ft_move_line.c\
			move/ft_move_word.c\
			pipe/ft_pipe.c\
			pipe/ft_pipe_misc.c\
			quote/ft_dquote.c\
			quote/ft_dquote_misc.c\
			quote/ft_is_quoted.c\
			quote/ft_quote.c\
			quote/ft_quote_misc.c\
			redirection/ft_double_right.c\
			redirection/ft_redirect.c\
			redirection/ft_redirect_left.c\
			redirection/ft_redirect_misc.c\
			redirection/ft_redirect_right.c\
			redirection/ft_single_left.c\
			redirection/ft_single_right.c\
			term/ft_term.c\
			term/ft_term_misc.c
SRC_PATH = srcs
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(SRC:.c=.o)
CC = clang
CPPFLAGS = -Iincludes
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

lft:
	$(MAKE) -C libft

$(NAME): $(OBJ)
	$(CC) $^ -o $@ -Llibft -lft -ltermcap

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY : all, clean, fclean, re, lft
