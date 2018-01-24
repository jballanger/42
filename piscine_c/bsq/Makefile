# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/20 13:44:39 by jballang          #+#    #+#              #
#    Updated: 2016/09/21 23:16:44 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

FILES = ./srcs/main.c ./srcs/is_valid.c ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/jesus_fill.c ./srcs/search.c ./srcs/get_max.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FILES)
	@gcc -o $(NAME) main.o is_valid.o ft_putchar.o ft_putstr.o jesus_fill.o search.o get_max.o

clean:
	@rm -f main.o is_valid.o ft_putchar.o ft_putstr.o jesus_fill.o search.o get_max.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
