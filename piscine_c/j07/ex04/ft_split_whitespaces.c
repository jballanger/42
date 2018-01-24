/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:17:43 by jballang          #+#    #+#             */
/*   Updated: 2016/09/08 23:35:05 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest[i] = src;
	i++;
	dest[i] = '\0';
	return (dest);
}

char	separator(char str)
{
	if (str == 32 || str == 9 || str == 10)
		return (1);
	else
		return (-1);
}

char	**ft_split_whitespaces(char *str)
{
	char	**array;
	int		i;
	int		n;

	i = 0;
	n = 0;
	array = malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\0')
	{
		if (separator(str[i]) > 0)
			i++;
		else
		{
			while (separator(str[i]) < 0 && str[i] != '\0')
			{
				if (strlen(array[n]) > 0)
					array[n] = ft_strcat(array[n], (str + i));
				else
					array[n] = (str + i);
				i++;
			}
			n++;
		}
	}
	return (array);
}
