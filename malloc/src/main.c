/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:35:11 by jballang          #+#    #+#             */
/*   Updated: 2018/04/20 12:38:58 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	main(int ac, char **av)
{
	void	*ptr;
	void	*ptr2;
	void	*ptr3;

	ac = 777;
	av = NULL;
	ptr = malloc(25);
	ptr2 = malloc(50);
	ptr3 = (char*)malloc(7);
	ft_memcpy(ptr3, "super", 5);
	ft_putendl(ptr3);
	//show_alloc_memory();
}
