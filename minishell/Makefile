NAME = minishell
SRC_NAME = 	main.c\
			parser.c\
			builtins.c\
			ft_cd.c\
			ft_echo.c\
			ft_setenv.c\
			ft_unsetenv.c\
			ft_env.c\
			ft_env_func.c\
			get_next_line.c\
			ft_misc.c\
			ft_get.c\
			ft_env_add.c\
			ft_separator.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = srcs
OBJ_PATH = obj
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_CC = $(SRC:-Iincludes.c=.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ_CC)
	$(MAKE) -C libft
	gcc $(FLAGS) -Iincludes -c $(SRC)
	gcc -o $(NAME) -Iincludes $(SRC) -Llibft -lft
	mkdir -p $(OBJ_PATH)
	mv $(OBJ_NAME) obj/

all: $(NAME)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY : all, clean, fclean, re
