/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 09:25:36 by jballang          #+#    #+#             */
/*   Updated: 2017/05/15 09:25:51 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_history(t_term *term, char *cmd)
{
	ft_lstadd(&term->history, ft_lstnew(cmd, ft_strlen(cmd)));
	term->history_len++;
}
