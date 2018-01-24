/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:38:42 by jballang          #+#    #+#             */
/*   Updated: 2017/06/01 14:27:44 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **input)
{
	size_t	i;
	int		status;

	i = 0;
	status = 0;
	if (input[1])
	{
		while (input[1][i] && ft_isdigit(input[1][i]))
			i++;
		if (i == ft_strlen(input[1]))
			status = ft_atoi(input[1]);
		else
		{
			ft_putstr_fd("21sh: exit: Illegal number: ", 2);
			ft_putendl_fd(input[1], 2);
		}
	}
	if (!input[1] || i == ft_strlen(input[1]))
	{
		if (g_term.piping == 1)
			ft_restore_term(&g_term.old_term);
		exit(status);
	}
}
