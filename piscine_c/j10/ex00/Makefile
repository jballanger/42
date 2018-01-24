# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 10:57:53 by jballang          #+#    #+#              #
#    Updated: 2016/09/12 19:52:45 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = /srcs/ft_putchar.c /srcs/ft_putstr.c /srcs/ft_strcmp.c /srcs/ft_strlen.c /srcs/ft_swap.c

HEADERS = /includes/

OFILES = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

$(NAME): make.o
	ar rc $(NAME) $(OFILES)

make.o:
	gcc -Wall -Wextra -Werror -I$(HEADERS) -c $(SRC)

clean:
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re: fclean all
