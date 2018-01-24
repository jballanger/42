/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:00:18 by mleroi            #+#    #+#             */
/*   Updated: 2016/09/14 17:10:31 by mleroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *i;

	i = (t_list*)malloc(sizeof(t_list) * 1);
	if (i == 0)
		return (NULL);
	i->data = data;
	i->next = 0;
	return (i);
}
