/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 16:56:21 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 20:12:27 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*next_list;

	list = NULL;
	while (list != NULL)
	{
		next_list = list->next;
		list->next = *begin_list;
		*begin_list = list;
		list = next_list;
	}
}
