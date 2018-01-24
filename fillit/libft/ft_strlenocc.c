/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenocc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:37:22 by jballang          #+#    #+#             */
/*   Updated: 2016/11/30 14:39:30 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenocc(char *str, char occ)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == occ)
			i++;
		str++;
	}
	return (i);
}