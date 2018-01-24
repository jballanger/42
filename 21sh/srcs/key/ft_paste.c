/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 09:35:08 by jballang          #+#    #+#             */
/*   Updated: 2017/05/24 09:36:28 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_paste_empty(t_term *term)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(term->copy) + 1));
	while (term->copy[i])
	{
		str[i] = term->copy[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_paste_between(t_term *term)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(term->cmd) +\
		ft_strlen(term->copy) + 1));
	while (i++ < (term->x - 3) - 1)
		str[i] = term->cmd[i];
	while (term->copy[j])
		str[i++] = term->copy[j++];
	j = term->x - 3;
	while (term->cmd[j])
		str[i++] = term->cmd[j++];
	str[i] = '\0';
	return (str);
}

void	ft_paste(t_term *term)
{
	char	*str;

	if (term->copy)
	{
		if (term->cmd)
			str = ft_paste_between(term);
		else
			str = ft_paste_empty(term);
		free(term->cmd);
		term->cmd = str;
		ft_rewrite_cmd(term);
	}
}
