/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 12:09:18 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 20:46:32 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*new_tab;

	i = 0;
	if (!(new_tab = (int*)malloc(sizeof(int) * length)))
		return (0);
	while (i < length && tab[i])
	{
		new_tab[i] = f(tab[i]);
		i++;
	}
	return (new_tab);
}
