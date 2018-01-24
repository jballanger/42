/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 09:30:33 by jballang          #+#    #+#             */
/*   Updated: 2017/05/10 11:09:05 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_alt(t_term *term, char buff[6])
{
	if (buff[0] == -61 && buff[1] == -89)
		ft_copy(term);
	else if (buff[0] == -30 && buff[1] == -120 && buff[2] == -102)
		ft_paste(term);
	else if (buff[3] == 65)
		ft_move_line_top(term);
	else if (buff[3] == 66)
		ft_move_line_bot(term);
	else if (buff[3] == 67)
		ft_move_word_right(term);
	else if (buff[3] == 68)
		ft_move_word_left(term);
}
