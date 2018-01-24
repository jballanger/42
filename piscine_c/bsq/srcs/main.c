/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 10:57:54 by jballang          #+#    #+#             */
/*   Updated: 2016/09/21 21:32:58 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 1
#include "../includes/header.h"

char	*ft_realloc(char *buf, int size)
{
	char	*newbuf;
	int		i;

	i = 0;
	while (buf[i])
		i++;
	if ((newbuf = malloc(sizeof(char*) * ((size + BUF_SIZE)))) == NULL)
		return (NULL);
	i = 0;
	while (buf[i] != '\0')
	{
		newbuf[i] = buf[i];
		i++;
	}
	free(buf);
	return (newbuf);
}

int		fill_in(void)
{
	int		ret;
	int		size;
	char	*buf;

	buf = malloc(sizeof(char) * BUF_SIZE);
	if (buf == NULL)
		return (1);
	ret = read(0, buf, BUF_SIZE);
	size = 1;
	while (ret > 0)
	{
		buf[size] = '\0';
		buf = ft_realloc(buf, size);
		ret = read(0, (buf + size), 1);
		size++;
	}
	buf[size - 1] = '\0';
	if (is_valid(buf) > 0)
		return (1);
	return (0);
}

int		fill(int fd)
{
	int		ret;
	int		size;
	char	*buf;

	buf = malloc(sizeof(char) * BUF_SIZE);
	if (buf == NULL)
		return (1);
	ret = read(fd, buf, BUF_SIZE);
	size = ret;
	while (ret > 0)
	{
		buf[size] = '\0';
		buf = ft_realloc(buf, size);
		ret = read(fd, (buf + size), BUF_SIZE);
		size++;
	}
	buf[size] = '\0';
	if (is_valid(buf) > 0)
		return (1);
	return (0);
}

int		get_fd(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
	{
		if (fill_in() > 0)
			ft_putstr("map error\n");
	}
	else
	{
		while (argv[i])
		{
			if (get_fd(argv[i]) > -1)
			{
				if (fill(get_fd(argv[i])) > 0)
					ft_putstr("map error\n");
			}
			else
				ft_putstr("map error\n");
			if (argv[i + 1])
				ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
