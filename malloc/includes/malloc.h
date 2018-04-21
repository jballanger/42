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

typedef struct		s_header
{
	size_t			size;
	void			*address;
	char			free;
	struct s_header	*next;
	struct s_header	*prev;
}					t_header;

typedef struct		s_page
{
	char			type;
	void			*address;
	size_t			available;
	struct s_page	*next;
}					t_page;

typedef struct		s_mem
{
	struct s_page	*pages;
}					t_mem;

t_mem				g_mem;

void				*malloc(size_t size);
void				ft_free(void *ptr);
void				show_alloc_memory();

#endif
