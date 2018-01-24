/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:40:59 by jballang          #+#    #+#             */
/*   Updated: 2017/02/01 11:19:46 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putparam(char *p1, char *p2, char *p3, char *p4)
{
	if (p1)
		ft_putstr(p1);
	if (p2)
		ft_putstr(p2);
	if (p3)
		ft_putstr(p3);
	if (p4)
		ft_putstr(p4);
}

void	ft_putcn(int order, char *str, int nb, int nl)
{
	if (order == 1)
	{
		ft_putstr(str);
		ft_putnbr(nb);
	}
	else if (order == 2)
	{
		ft_putnbr(nb);
		ft_putstr(str);
	}
	if (nl == 1)
		ft_putchar('\n');
}

void	ft_opendirerr(char *dirname, char *error)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(dirname, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
}

char	*ft_dirjoin(char *path, char *file)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (ft_strjoin(path, file));
	return (ft_strjoin(ft_strjoin(path, "/"), file));
}

char	*ft_tsmp(time_t tsmp)
{
	time_t	now;

	now = time(NULL);
	if (tsmp > now || tsmp < (now - 15778800))
	{
		return (ft_strjoin(ft_strjoin(ft_strsub(ctime(&tsmp), 4, 6), " "),\
				ft_strsub(ctime(&tsmp), 19, 5)));
	}
	return (ft_strsub(ctime(&tsmp), 4, 12));
}
