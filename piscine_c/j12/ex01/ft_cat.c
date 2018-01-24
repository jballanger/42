/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 10:49:54 by jballang          #+#    #+#             */
/*   Updated: 2016/09/15 22:59:14 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(int fd, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	cat_file(char *filename)
{
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(2, "ft_cat: ");
		ft_putstr_fd(2, filename);
		ft_putstr_fd(2, ": No such file or directory\n");
	}
	else
	{
		while (read(fd, &c, 1) > 0)
			write(1, &c, 1);
		if (read(fd, &c, 1) == -1)
		{
			ft_putstr_fd(2, "ft_cat: ");
			ft_putstr_fd(2, filename);
			ft_putstr_fd(2, ": Is a directory\n");
		}
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*buffer[28672];

	i = 1;
	if (argc == 1)
	{
		while (read(0, buffer, 1))
		{
			write(1, buffer, 1);
		}
	}
	else
	{
		while (argv[i])
		{
			cat_file(argv[i]);
			i++;
		}
	}
	return (0);
}
