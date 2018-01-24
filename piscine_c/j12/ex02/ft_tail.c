/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 11:21:57 by jballang          #+#    #+#             */
/*   Updated: 2016/09/15 16:52:54 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		ft_atoi(char *str);

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

void	ft_tail(char *filename, char *nb)
{
	int		fd;
	int		nbr;
	char	c;

	nbr = ft_atoi(nb);
	if (nbr < 0)
		nbr = -nbr;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd(2, "open() failed");
	else
	{
		lseek(fd, -nbr, SEEK_END);
		while (read(fd, &c, 1) != 0)
		{
			write(1, &c, 1);
		}
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 3;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		ft_tail(argv[i], argv[2]);
		i++;
	}
	return (0);
}
