/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:30:06 by jballang          #+#    #+#             */
/*   Updated: 2018/04/19 15:34:34 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_malloc(size_t size)
{
	t_header	*header;
	void		*block;
	size_t		total_size;

	header = find_block(size);
	if (header)
	{
		header->free = 0;
		// unlock mutex
		return (void*)(header + 1);
	}
	total_size = size + sizeof(t_header);
	block = mmap(0, total_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
		-1, 0);
	if (block == (void*)-1)
	{
		// unlock mutex
		return (NULL);
	}
	header = block;
	header->size = size;
	header->free = 0;
	header->next = NULL;
	if (!head)
		head = header;
	if (tail)
		tail->next = header;
	tail = header;
	// unlock mutex
	return (void*)(header + 1);
}
