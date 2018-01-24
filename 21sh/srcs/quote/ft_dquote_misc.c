/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dquote_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:01:30 by jballang          #+#    #+#             */
/*   Updated: 2017/06/02 14:23:38 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dquotesafeclear(t_term *term)
{
	if (term->dquote_prompt)
		free(term->dquote_prompt);
	if (term->dquote_cmd)
		free(term->dquote_cmd);
}
