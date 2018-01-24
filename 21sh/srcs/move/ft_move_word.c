/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:31:59 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 13:56:06 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_int_change(int *a, int *b)
{
	*a += 1;
	*b -= 1;
}

void	ft_int_up(int *a, int *b)
{
	*a += 1;
	*b += 1;
}

int		is_space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_move_word_right(t_term *term)
{
	int		i;
	int		j;
	char	*tmp;

	i = term->x - 3;
	j = 0;
	if (term->cmd && term->x < term->max_x)
	{
		tmp = ft_strdup(term->cmd);
		if ((size_t)i < ft_strlen(tmp) && is_space_tab(tmp[i + 1]))
			ft_int_up(&j, &i);
		while (tmp[i] && is_space_tab(tmp[i]))
			ft_int_up(&j, &i);
		while (tmp[i] && !is_space_tab(tmp[i]))
			ft_int_up(&j, &i);
		while (j > 0)
		{
			ft_move_right(term);
			j--;
		}
		if (is_space_tab(tmp[i]) || tmp[i] == 0)
			ft_move_left(term);
		free(tmp);
	}
}

void	ft_move_word_left(t_term *term)
{
	int		i;
	int		j;
	char	*tmp;

	i = term->x - 3;
	j = 0;
	if (term->cmd && term->x > term->min_x)
	{
		tmp = ft_strdup(term->cmd);
		if ((size_t)i == ft_strlen(term->cmd))
			ft_int_change(&j, &i);
		if (i > 0 && is_space_tab(tmp[i - 1]))
			ft_int_change(&j, &i);
		while (tmp[i] && is_space_tab(tmp[i]))
			ft_int_change(&j, &i);
		while (tmp[i] && !is_space_tab(tmp[i]))
			ft_int_change(&j, &i);
		while (j-- > 0)
			ft_move_left(term);
		if (is_space_tab(tmp[i]))
			ft_move_right(term);
		free(tmp);
	}
}
