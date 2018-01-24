/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:47:31 by jballang          #+#    #+#             */
/*   Updated: 2017/06/05 13:47:55 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_read_key(char buff[6], t_term *term, int prompt)
{
	if (buff[0] == 27 || buff[0] == -61 || buff[0] == -30)
		ft_move(term, buff);
	else if (buff[0] == 127)
		ft_backspace(term);
	else if (buff[0] == '\n')
		ft_return(term);
	else if (buff[0] == 12)
		ft_clear_screen(term);
	else if (buff[0] == 4)
		ft_eof(term);
	else if (ft_isprint(buff[0]))
	{
		if (term->cmd && term->cmd[term->x - prompt] != 0)
			ft_add_char_between(term, buff[0]);
		else
			ft_add_char(term, buff[0]);
	}
}
