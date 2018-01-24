# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/14 11:22:23 by jballang          #+#    #+#              #
#    Updated: 2016/09/15 16:13:35 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

FILES = ft_tail.c ft_atoi.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(FILES)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
