/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:48:19 by jballang          #+#    #+#             */
/*   Updated: 2018/04/19 13:22:21 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define BLOCK_SIZE sizeof(struct s_block)

# include "../libft/libft.h"

# include <sys/mman.h>
# include <unistd.h>

typedef struct s_block	*t_block;

struct	s_block
{
	size_t	size;
	t_block	next;
	int			free;
};

extern void	*base;
void *base;

t_block	find_block(t_block *last, size_t size);

#endif
