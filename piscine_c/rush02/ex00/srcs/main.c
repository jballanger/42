/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 12:41:55 by jballang          #+#    #+#             */
/*   Updated: 2016/09/20 15:34:26 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*make_buffer(char *buffer, t_list *list, int size)
{
	t_list	*tmp_list;

	buffer = (char*)malloc(sizeof(char) * size);
	while (size > 0)
	{
		buffer[size - 1] = list->data;
		size--;
		tmp_list = list;
		list = list->next;
		free(tmp_list);
	}
	return (buffer);
}

t_list	*ft_list_add(t_list **list, char data)
{
	t_list *elem;

	elem = NULL;
	elem = ft_create_elem(data);
	elem->next = *list;
	return (elem);
}

void	checker(char *str)
{
	if (str[0] == 'o')
		colle00(str);
	else if (str[0] == '/')
		colle01(str);
	else if (str[0] == 'A')
	{
		colle234(str);
	}
	else
		write(1, "aucune\n", 7);
}

int		main(void)
{
	t_list	*list;
	char	*buffer;
	char	c;
	int		size;

	list = NULL;
	buffer = NULL;
	size = 0;
	while (read(0, &c, 1))
	{
		list = ft_list_add(&list, c);
		size++;
	}
	buffer = make_buffer(buffer, list, size);
	checker(buffer);
	return (0);
}
