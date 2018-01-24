/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:43:40 by jballang          #+#    #+#             */
/*   Updated: 2017/06/02 14:03:02 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_copy(t_term *term, char c)
{
	size_t	i;
	char	*str;

	if (term->copy)
		i = ft_strlen(term->copy);
	else
		i = 0;
	str = (char*)malloc(sizeof(char) * (i + 2));
	i = 0;
	str[i++] = c;
	if (term->copy)
	{
		while (term->copy[i - 1])
		{
			str[i] = term->copy[i - 1];
			i++;
		}
	}
	str[i] = '\0';
	free(term->copy);
	term->copy = str;
}

void	ft_remove_copy(t_term *term)
{
	size_t	i;
	char	*str;

	i = ft_strlen(term->copy);
	if (i > 0)
	{
		str = (char*)malloc(sizeof(char) * i);
		i = 1;
		while (term->copy && term->copy[i])
		{
			str[i - 1] = term->copy[i];
			i++;
		}
		str[i - 1] = '\0';
		free(term->copy);
		term->copy = str;
	}
}

void	ft_first_copy(t_term *term, char c)
{
	char	*str;

	if (term->copy)
		free(term->copy);
	str = (char*)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	term->copy = str;
}

void	ft_move_left_copy(t_term *term, char c)
{
	int		i;

	i = 0;
	write(0, &c, 1);
	ft_add_copy(term, c);
	tputs(tgetstr("le", NULL), 1, int_putchar);
	if (((term->x + 1) % term->col) == 0)
	{
		while (i++ < term->col)
			tputs(tgetstr("nd", NULL), 1, int_putchar);
	}
}

void	ft_copy(t_term *term)
{
	char	c;

	if (term->cmd)
		c = term->cmd[term->x - term->prompt_len];
	else
		c = 0;
	if (c && c != '\0')
	{
		if (term->copy_mode == 0)
		{
			tputs(tgetstr("mr", NULL), 1, int_putchar);
			write(0, &c, 1);
			ft_move_left(term);
			term->x++;
			term->copy_mode = 1;
			ft_first_copy(term, c);
		}
		else
		{
			tputs(tgetstr("me", NULL), 1, int_putchar);
			term->copy_mode = 0;
			ft_rewrite_cmd(term);
		}
	}
}
