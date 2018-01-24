/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 21:34:04 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 21:39:03 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list1;
	t_list	*list2;

	list1 = *begin_list1;
	list2 = begin_list2;
	while (list1 != NULL)
		list1 = list1->next;
	while (list2 != NULL)
	{
		list1 = list2;
		list1 = list1->next;
		list2 = list2->next;
	}
}
