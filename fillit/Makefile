NAME = fillit
SRC_NAME = main.c fillit.c check.c position.c logic.c get_position.c fill_square.c ft_rrange.c
SRC_PATH = srcs
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_NAME = $(SRC:.c=.o)
OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CPPFLAGS = -Iincludes
CC = clang
CFLAGS = -Werror -Wall -Wextra
LIBFT_PATH = libft
LIBFT = libft.a

.PHONY: clean, fclean, re

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBFT_PATH)
	@$(CC) $(CPPFLAGS) -o $(NAME) $(SRC) $(LIBFT_PATH)/$(LIBFT)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all