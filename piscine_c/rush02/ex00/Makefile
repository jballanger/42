# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 22:13:14 by jballang          #+#    #+#              #
#    Updated: 2016/09/18 15:59:21 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

FILES = ./srcs/main.c ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcat.c ./srcs/ft_putnbr.c ./srcs/fake.c ./srcs/fake00.c ./srcs/create_real00.c ./srcs/ft_strcmp.c ./srcs/ft_create_elem.c ./srcs/printer.c ./srcs/colle00.c ./srcs/colle01.c ./srcs/colle234.c ./srcs/fake01.c ./srcs/fake02.c ./srcs/fake03.c ./srcs/fake04.c ./srcs/create_real01.c ./srcs/create_real02.c ./srcs/create_real03.c ./srcs/create_real04.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -o $(NAME) $(FILES)

clean:
	@rm -f nothing.o

fclean:
	@rm -f $(NAME)

re: fclean all
