/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 09:59:44 by jballang          #+#    #+#             */
/*   Updated: 2016/09/15 18:44:42 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

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

int		main(int argc, char **argv)
{
	int		fd;
	char	c;

	if (argc > 2)
		ft_putstr_fd(2, "Too many arguments.\n");
	else if (argc < 2)
		ft_putstr_fd(2, "File name missing.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_putstr_fd(2, "open() failed\n");
		else
		{
			while (read(fd, &c, 1) != 0)
				write(1, &c, 1);
			close(fd);
		}
	}
	return (0);
}
