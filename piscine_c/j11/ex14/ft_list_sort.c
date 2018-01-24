/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 21:40:34 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 22:04:01 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	t_list	*list_next;
	int		swap;

	swap = 0;
	while (swap == 0)
	{
		swap = 1;
		list = *begin_list;
		list_next = *begin_list;
		list_next = list_next->next;
		while (list_next != NULL)
		{
			if (cmp(list->data, list_next->data) > 0)
			{
				list->next = *begin_list;
				*begin_list = list;
				list = list->next;
				swap = 0;
			}
			list = list->next;
			list_next = list_next->next;
		}
	}
}
