/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:13:45 by jballang          #+#    #+#             */
/*   Updated: 2017/05/30 14:04:47 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shift_right(t_term *term, int pos, char replace)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(term->cmd) + 2));
	while (i < pos)
	{
		str[i] = term->cmd[i];
		i++;
	}
	str[i++] = replace;
	while ((i - 1) < (int)ft_strlen(term->cmd))
	{
		str[i] = term->cmd[i - 1];
		i++;
	}
	str[i] = '\0';
	free(term->cmd);
	term->cmd = str;
}

void	shift_left(t_term *term, int pos)
{
	while (term->cmd[pos + 1])
	{
		term->cmd[pos] = term->cmd[pos + 1];
		pos++;
	}
	term->cmd[pos] = '\0';
	if (pos == 0)
	{
		free(term->cmd);
		term->cmd = NULL;
	}
}
