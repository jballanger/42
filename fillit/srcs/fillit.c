/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:13:35 by jballang          #+#    #+#             */
/*   Updated: 2016/11/25 14:43:28 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	leave(void)
{
	ft_putendl("error");
	exit(0);
}

static char	*get_content(char *source)
{
	char	*buffer;
	int		fd;
	int		ret;

	if (!(buffer = (char*)malloc(sizeof(char) * BUF_SIZE)))
		return (NULL);
	fd = open(source, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buffer, BUF_SIZE);
	close(fd);
	return (buffer);
}

void		fillit(char *source)
{
	if (!(source = get_content(source)))
		leave();
	if (check(source))
		logic(check(source));
	else
		leave();
}
