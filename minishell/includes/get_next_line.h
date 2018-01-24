/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:21:52 by jballang          #+#    #+#             */
/*   Updated: 2017/02/22 11:56:37 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <strings.h>
# include "../libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_line
{
	int				fd;
	char			*buffer;
	struct s_line	*next;
}					t_line;

#endif
