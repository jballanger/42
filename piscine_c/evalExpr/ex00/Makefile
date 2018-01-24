# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 08:00:39 by jballang          #+#    #+#              #
#    Updated: 2016/09/17 12:35:22 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = evalExpr

LIBNAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putnbr.c ./srcs/eval_expr.c ./srcs/calc.c ./srcs/ft_atoi.c

FILES.o = ft_putchar.o ft_putnbr.o eval_expr.o calc.o ft_atoi.o

all: $(NAME)

$(NAME): do

do: compile lib
	@gcc -Wall -Wextra -Werror -o $(NAME) main.c -L. -lft

compile:
	@gcc -Wall -Wextra -Werror  -c $(SRC)

lib:
	@ar rc $(LIBNAME) $(FILES.o)

clean:
	@rm -f ./$(FILES.o)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
