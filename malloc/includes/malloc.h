/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:48:19 by jballang          #+#    #+#             */
/*   Updated: 2018/04/20 12:50:13 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define BLOCK_SIZE sizeof(struct s_header)
# define TINY 128
# define SMALL 2048
# define LARGE 0x0

# define TINY_MAX (8 * getpagesize())
# define SMALL_MAX (64 * getpagesize())

# include "../libft/libft.h"

# include <sys/mman.h>
# include <unistd.h>

typedef struct		s_header
{
	size_t			size;
	void			*address;
	char			free;
	struct s_header	*next;
	struct s_header	*prev;
}					t_header;

typedef struct		s_mem
{
					
}					t_mem;

t_mem				g_mem;

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
t_header			*find_block(size_t size);
void				show_alloc_memory();

#endif
