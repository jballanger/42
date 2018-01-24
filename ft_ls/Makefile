NAME = ft_ls
SRC_NAME = 	ft_dir.c\
			ft_files.c\
			ft_sort.c\
			ft_stats.c\
			main.c\
			opt.c\
			parser.c\
			leave.c\
			misc.c\
			get_max.c\
			opt_rev.c\
			opt_rec.c\
			opt_l.c\
			opt_l_func.c\
			opt_l_get.c\
			lsl.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = srcs
OBJ_PATH = obj
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_CC = $(SRC:-Iincludes.c=.o)
FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ_CC)
	@$(MAKE) -C libft
	@gcc $(FLAGS) -Iincludes -c $(SRC)
	@gcc -o $(NAME) -Iincludes $(SRC) -Llibft -lft
	@mkdir -p $(OBJ_PATH)
	@mv $(OBJ_NAME) obj/

all: $(NAME)

clean:
	@$(MAKE) clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -rf $(NAME)

re: fclean all