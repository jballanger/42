/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:48:19 by jballang          #+#    #+#             */
/*   Updated: 2018/04/19 15:37:44 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define BLOCK_SIZE sizeof(struct s_header)

# include "../libft/libft.h"

# include <sys/mman.h>
# include <unistd.h>

typedef struct s_header	t_header;

struct		s_header
{
	size_t		size;
	int			free;
	t_header	*next;
};

extern t_header	*g_head;
extern t_header	*g_tail;
t_header *g_head;
t_header *g_tail;

void		*ft_malloc(size_t size);
t_header	*find_block(size_t size);

#endif
