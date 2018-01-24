/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:11:26 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 20:20:36 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*begin_list;
	int		i;

	list = NULL;
	begin_list = list;
	i = 1;
	while (ac > i)
	{
		list = ft_create_elem(av[ac - 1]);
		ac--;
	}
	return (begin_list);
}
