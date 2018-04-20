/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:30:06 by jballang          #+#    #+#             */
/*   Updated: 2018/04/20 12:43:26 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
void	*ft_alloc(size_t size)
{
	void	*page;

	page = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,
		0);
	if (page == MAP_FAILED)
		return (NULL);
	return (page);
}

void	*ft_malloc(size_t type_max, size_t size)
{

	if (g_mem.head)
	{
		// find block
	}
	g_mem.head = ft_alloc(type_max);

	/*t_header	*header;
	void		*block;

	header = find_block(size);
	if (header)
	{
		header->free = 0;
		return (void*)(header + 1);
	}
	ft_putendl("Calling mmap");
	block = mmap(0, TINY_MAX, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
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
	if (!g_head)
		g_head = header;
	if (g_tail)
		g_tail->next = header;
	g_tail = header;
	// unlock mutex
	return (void*)(header + 1);*/

}

void	*f_malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	else if (size <= TINY)
		return ft_malloc(TINY_MAX, size);
	else if (size <= SMALL)
		return ft_malloc(SMALL_MAX, size);
	else
		return ft_malloc(LARGE, size);
}

void	show_alloc_memory()
{
	t_header	*header;

	header = g_head;
	while (header)
	{
		ft_putendl("----------------");
		ft_putstr("Size: ");
		ft_putnbr(header->size);
		ft_putstr("\nAllocated: ");
		ft_putendl((header->free) ? "No" : "Yes");
		header = header->next;
	}
}
