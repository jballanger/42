# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jballang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/14 12:53:10 by jballang          #+#    #+#              #
#    Updated: 2016/09/14 13:16:01 by jballang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump

FILES = ft_hexdump.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(FILES)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
