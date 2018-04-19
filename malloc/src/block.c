/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:58:33 by jballang          #+#    #+#             */
/*   Updated: 2018/04/19 15:32:28 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_header	*find_block(size_t size)
{
	t_header	*b;

	b = head;
	while (b)
	{
		if (b->free && b->size >= size)
			return (b);
		b = b->next;
	}
	return (NULL);
}

/*t_header	extend_heap(t_header last, size_t size)
{
	t_header	b;

	b = mmap()
	if (mmap(BLOCK_SIZE + size) == (void*)-1)
	{
		return (NULL);
	}

}*/
