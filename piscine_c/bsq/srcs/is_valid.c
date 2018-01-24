/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:47:35 by jballang          #+#    #+#             */
/*   Updated: 2016/09/21 19:40:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		get_nb(char *buf, int i)
{
	int		nbr;
	int		p;

	nbr = 0;
	p = 0;
	while (i >= 4)
	{
		nbr *= 10;
		nbr += (buf[p] - 48);
		i--;
		p++;
	}
	return (nbr);
}

int		check_lines(char *buf, int lines)
{
	int		i;
	int		bs_n;

	i = 0;
	bs_n = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			bs_n++;
		i++;
	}
	if ((bs_n - 1) != lines)
		return (1);
	return (0);
}

int		check_infos(char *buf, char infos[3])
{
	int		i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	while (buf[i] != '\0')
	{
		if (buf[i] != infos[0] && buf[i] != infos[1]
				&& buf[i] != infos[2] && buf[i] != '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		anti_cheat(char *buf, int lines, char infos[3])
{
	if (check_lines(buf, lines) > 0)
		return (1);
	if (check_infos(buf, infos) > 0)
		return (1);
	return (0);
}

int		is_valid(char *buf)
{
	int		i;
	int		lines;
	char	infos[3];

	i = 0;
	while (buf[i] != '\n')
	{
		i++;
	}
	if (i > 4)
		lines = get_nb(buf, i);
	else
		lines = buf[0] - 48;
	infos[0] = buf[i - 3];
	infos[1] = buf[i - 2];
	infos[2] = buf[i - 1];
	if (anti_cheat(buf, lines, infos) > 0)
		return (1);
	jesus_fill(buf, infos);
	return (0);
}
