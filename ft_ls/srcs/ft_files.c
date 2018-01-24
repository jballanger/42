/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:27:02 by jballang          #+#    #+#             */
/*   Updated: 2017/02/02 11:00:41 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files		*ft_filesnew(char name[], int type, char *error)
{
	t_files		*new;

	if (!(new = malloc(sizeof(t_files))))
		return (NULL);
	if (name && type)
	{
		ft_strcpy(new->name, name);
		new->type = type;
	}
	else
	{
		new->name[0] = '\0';
		new->type = type;
	}
	if (error)
	{
		if (!(new->error = (char*)malloc(sizeof(char) * ft_strlen(error))))
			return (NULL);
		ft_bzero(new->error, ft_strlen(error));
		ft_strcpy(new->error, error);
	}
	else
		new->error = NULL;
	new->next = NULL;
	return (new);
}

void		ft_filespush(t_files **alst, t_files *new)
{
	t_files		*tmp;

	tmp = *alst;
	if (new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		ft_filesadd(t_files **alst, t_files *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

int			ft_filesrange(t_files *lst)
{
	t_files	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
