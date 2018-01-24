/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 15:13:45 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 13:48:08 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_backspace(t_term *term)
{
	if (term->x > term->min_x)
	{
		tputs(tgetstr("le", NULL), 1, int_putchar);
		tputs(tgetstr("dc", NULL), 0, int_putchar);
		term->x--;
		term->max_x--;
		term->cmd[term->x - (term->prompt_len)] = 0;
		shift_left(term, (term->x) - term->prompt_len);
		ft_rewrite_cmd(term);
	}
}

void	ft_return(t_term *term)
{
	char	*trim;

	write(0, "\n", 1);
	term->x = 3;
	term->max_x = 3;
	term->min_x = 3;
	term->history_pos = 0;
	if (!term->cmd)
		term->cmd = ft_strdup(" ");
	if (term->heredocument == 0 && term->dquote == 0)
	{
		trim = ft_strtrim(term->cmd);
		if (ft_strlen(trim) > 0)
			ft_add_history(term, term->cmd);
		main_loop(trim);
		free(trim);
	}
	else if (term->heredocument == 1)
		heredoc_loop(term->cmd);
	else if (term->dquote == 1)
		dquote_loop(term->cmd);
	free(term->cmd);
	free(term->cmd_temp);
	term->cmd = NULL;
	term->cmd_temp = NULL;
}

void	ft_add_char_between(t_term *term, char c)
{
	shift_right(term, (term->x - term->prompt_len), c);
	term->x++;
	if ((term->x) % term->col == 0)
		tputs(tgetstr("do", NULL), 1, int_putchar);
	else
		tputs(tgetstr("nd", NULL), 1, int_putchar);
	ft_rewrite_cmd(term);
}

void	ft_add_char(t_term *term, char c)
{
	int		i;
	char	*str;

	i = 0;
	write(0, &c, 1);
	term->x++;
	term->max_x++;
	if (!term->cmd)
		str = (char*)malloc(sizeof(char) * 2);
	else
	{
		str = (char*)malloc(sizeof(char) * (ft_strlen(term->cmd) + 2));
		while (term->cmd[i])
		{
			str[i] = term->cmd[i];
			i++;
		}
		free(term->cmd);
	}
	str[i++] = c;
	str[i] = '\0';
	term->cmd = str;
}

void	read_input(t_term *term)
{
	ssize_t	ret;
	char	buff[6];

	while ((ret = read(0, buff, 6)))
	{
		ft_columns(term);
		ft_read_key(buff, term, term->prompt_len);
	}
}
