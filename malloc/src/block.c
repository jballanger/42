/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:58:33 by jballang          #+#    #+#             */
/*   Updated: 2018/04/19 12:29:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block	find_block(t_block *last, size_t size)
{
	t_block	b;

	b = base;
	while (b && (!b->free || b->size < size))
	{
		*last = b;
		b = b->next;
	}
	return (b);
}

/*t_block	extend_heap(t_block last, size_t size)
{
	t_block	b;

	b = mmap()
	if (mmap(BLOCK_SIZE + size) == (void*)-1)
	{
		return (NULL);
	}

}*/
