/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:55:34 by jballang          #+#    #+#             */
/*   Updated: 2016/09/14 15:58:33 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_hexdump(char *filename, int flag)
{
	int		fd;
	char	c;

	flag = 111;
	fd = open(filename, O_TEXT);
	if (fd == -1)
		ft_putstr_fd(2, "open() failed");
	else
	{
		while (read(fd, &c, 1))
			write(1, &c, 1);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (argc <= 1)
		ft_putstr_fd(2, "File name missing");
	else
	{
		if (argv[2] == "-c")
		{
			i++;
			flag = 1;
		}
		while (argv[i])
		{
			ft_hexdump(argv[i], flag);
			i++;
		}
	}
}
