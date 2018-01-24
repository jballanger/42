/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:18:44 by jballang          #+#    #+#             */
/*   Updated: 2017/06/06 10:58:19 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_cmd(t_term *term)
{
	tputs(tgetstr("dl", NULL), 0, int_putchar);
	ft_putstr("$> ");
	term->x = 3;
	term->max_x = 3;
}

void	ft_arrdel(char **arr)
{
	int		i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

int		int_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_countwordlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (i);
}
