# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 12:45:21 by jballang          #+#    #+#              #
#    Updated: 2016/09/13 13:24:13 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

FILES = doop.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_atoi.c operation.c check_error.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(FILES)

clean:
	/bin/rm -f $(NAME)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
