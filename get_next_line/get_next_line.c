/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:03:11 by jballang          #+#    #+#             */
/*   Updated: 2017/02/22 11:43:48 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cut_buffer(char **buffer, int i)
{
	char	*toto;

	toto = ft_strnew(ft_strlen(*buffer));
	ft_strcpy(toto, *buffer);
	free(*buffer);
	*buffer = NULL;
	if ((size_t)i < ft_strlen(toto))
		*buffer = ft_strsub(toto, i, ft_strlen(toto));
	free(toto);
	toto = NULL;
}

char	*buffer_join(char *buffer, char tmp[])
{
	char	cpy[ft_strlen(buffer)];
	char	tmpp[ft_strlen(tmp)];

	ft_bzero(cpy, ft_strlen(buffer));
	ft_bzero(tmpp, ft_strlen(tmp));
	ft_strcpy(cpy, buffer);
	ft_strcpy(tmpp, tmp);
	free(buffer);
	return (ft_strjoin(cpy, tmpp));
}

t_line	*insert_read(t_line *lst, int fd, char tmp[])
{
	t_line	*list;
	t_line	*new;

	list = lst;
	while (list->next && list->fd != fd)
		list = list->next;
	if (list->fd == fd)
	{
		if (!list->buffer)
			list->buffer = ft_strjoin("", tmp);
		else
			list->buffer = buffer_join(list->buffer, tmp);
	}
	else
	{
		if (!(new = malloc(sizeof(t_line))))
			return (NULL);
		new->fd = fd;
		if (!(new->buffer = malloc(BUFF_SIZE)))
			return (NULL);
		new->buffer = ft_strcpy(new->buffer, tmp);
		new->next = NULL;
		list->next = new;
	}
	return (lst);
}

char	*get_line(t_line *lst, const int fd, char **line, int i)
{
	t_line	*tmp;
	char	*ret;
	char	*pouet;

	tmp = lst;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp || !tmp->buffer)
		return (NULL);
	while (tmp->buffer[i] != '\n' && tmp->buffer[i] != '\0')
		i++;
	if (i == 0 && tmp->buffer[i] == '\0')
		return (NULL);
	ret = ft_strnew(i);
	pouet = ft_strsub(tmp->buffer, 0, i);
	ret = ft_strcpy(ret, pouet);
	free(pouet);
	pouet = NULL;
	if (tmp->buffer[i] == '\n')
		i++;
	cut_buffer(&tmp->buffer, i);
	*line = ret;
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*lst;
	char			tmp[BUFF_SIZE + 1];
	int				res;

	if (!lst)
	{
		if (!(lst = malloc(sizeof(t_line))))
			return (-1);
		lst->buffer = NULL;
		lst->next = NULL;
	}
	if ((get_line(lst, fd, line, 0)))
		return (1);
	ft_bzero(tmp, BUFF_SIZE);
	while ((res = read(fd, tmp, BUFF_SIZE)))
	{
		if (res < 1)
			return (res);
		tmp[BUFF_SIZE] = '\0';
		lst = insert_read(lst, fd, tmp);
		if (ft_strchr(tmp, '\n') && (get_line(lst, fd, line, 0)))
			return (1);
		ft_bzero(tmp, BUFF_SIZE);
	}
	return (0);
}
