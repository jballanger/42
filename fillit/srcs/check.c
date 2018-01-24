/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:15:00 by jballang          #+#    #+#             */
/*   Updated: 2016/11/25 17:54:41 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*magic_replace(char *source)
{
	char	*new;
	char	*ret;

	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(source))))
		return (NULL);
	ret = new;
	while (*source != '\0')
	{
		if (*source == '\n' && *(source - 1) == '\n')
			source++;
		*new = *source;
		new++;
		if (*source != '\0')
			source++;
	}
	return (ret);
}

static int	check_content(char *source, int link)
{
	int	i;

	i = 0;
	while (*source != '\0')
	{
		if (*source == '\n' && *(source - 1) == '\n')
		{
			if (i != 4 || link < 6)
				return (0);
			i = 0;
			link = 0;
		}
		if (*source == '#' && i == 4)
			return (0);
		if (*source == '#')
		{
			link += position(source);
			i++;
		}
		source++;
	}
	if (i != 4 || link < 6)
		return (0);
	return (1);
}

static int	check_format(char *source, int i, int j)
{
	while (*source != '\0')
	{
		if (*source == '\n' && *(source - 1) == '\n')
		{
			source++;
			if (j != 4)
				return (0);
			j = 0;
		}
		while (*source == '.' || *source == '#')
		{
			i++;
			source++;
		}
		if (i != 4)
			return (0);
		i = 0;
		j++;
		source++;
	}
	if (*(source - 1) != '\n' || j != 4)
		return (0);
	return (1);
}

int			count_tetriminos(char *source)
{
	int	i;

	i = 1;
	while (*source != '\0')
	{
		if (*source == '\n' && *(source - 1) == '\n')
			i++;
		source++;
	}
	return (i);
}

char		*check(char *source)
{
	int	i;
	int	j;
	int	link;

	i = 0;
	j = 0;
	link = 0;
	if (count_tetriminos(source) > 26)
		return (0);
	if (!(check_format(source, i, j)))
		return (0);
	if (!(check_content(source, link)))
		return (0);
	source = magic_replace(source);
	return (source);
}
