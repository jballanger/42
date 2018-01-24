/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:27:51 by jballang          #+#    #+#             */
/*   Updated: 2017/02/02 10:56:43 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*ft_dirnew(char name[], t_files *files)
{
	t_dir	*new;

	if (!(new = malloc(sizeof(t_dir))))
		return (NULL);
	if (name)
	{
		ft_bzero(new->name, ft_strlen(name));
		ft_strcpy(new->name, name);
		new->files = files;
	}
	new->next = NULL;
	return (new);
}

void	ft_dirpush(t_dir **alst, t_dir *new)
{
	t_dir	*tmp;

	tmp = *alst;
	if (new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		ft_dirrange(t_dir **dir)
{
	t_dir	*tmp;
	int		i;

	tmp = *dir;
	i = 0;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->next->files->name[0] == '\0')
			{
				i++;
				tmp->next = tmp->next->next;
			}
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		ft_rdirrange(t_dir **dir)
{
	t_dir	*tmp;
	t_files	*tmp_files;
	int		i;

	tmp = *dir;
	i = 0;
	while (tmp)
	{
		tmp_files = tmp->files;
		while (tmp_files)
		{
			if (tmp_files->type == 4)
				i++;
			tmp_files = tmp_files->next;
		}
		tmp = tmp->next;
	}
	return (i);
}
