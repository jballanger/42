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
	ptr = f_malloc(25);
	ptr2 = f_malloc(50);
	ptr3 = f_malloc(7);
	show_alloc_memory();
}
