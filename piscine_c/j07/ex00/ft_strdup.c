/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:03:48 by jballang          #+#    #+#             */
/*   Updated: 2016/09/07 19:25:59 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	while (src[i] != '\0')
		i++;
	i++;
	str = (char*)malloc(sizeof(*str) * i);
	while (n < i)
	{
		str[n] = src[n];
		n++;
	}
	return (str);
}
