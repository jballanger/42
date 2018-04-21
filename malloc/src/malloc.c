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

	ft_putendl("call to mmap");
	page = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,
		0);
	if (page == MAP_FAILED)
		return (NULL);
	return (page);
}

void	*ft_malloc(char type, size_t type_max, size_t size)
{
	t_page	*page;

	page = g_mem.pages;
	while (page && 1 == 2)
	{
		ft_putstr((page->type == 1) ? "tiny" : "small");
		ft_putendl((type == 1) ? ":tiny" : ":small");
		if (page->type == type && page->available >= size)
		{
			ft_putendl("found enough space in a page");
			return (NULL);
		}
		page = page->next;
	}
	page = (t_page*)ft_alloc(type_max);
	page->type = type;
	//page->address = page;
	page->available = type_max;
	page->next = NULL;
	g_mem.pages = page;
	return ((void*)((page) /*+ sizeof(size_t)*/));
}

void	*malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	else if (size <= TINY)
		return ft_malloc(1, TINY_MAX, size);
	else if (size <= SMALL)
		return ft_malloc(2, SMALL_MAX, size);
	else
		return ft_malloc(3, 0, size);
}

void	show_alloc_memory()
{
	t_page	*page;

	page = g_mem.pages;
	while (page)
	{
		ft_putendl("----------------");
		ft_putstr("Type: ");
		ft_putchar(page->type);
		ft_putstr("\nAvailable: ");
		ft_putnbr(page->available);
		ft_putchar('\n');
		page = page->next;
	}
}
