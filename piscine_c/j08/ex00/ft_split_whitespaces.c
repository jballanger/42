/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:17:43 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 09:13:15 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	separator(char str)
{
	if (str == 32 || str == 9 || str == 10)
		return (1);
	else
		return (-1);
}

char	ft_strword(char *str)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	if (separator(str[0]) < 0)
		words++;
	while (str[i + 1] != '\0')
	{
		if ((separator(str[i]) > 0) && (separator(str[i + 1]) < 0))
			words++;
		i++;
	}
	if (separator(str[i]) < 0 && separator(str[i - 1]) > 0)
		words++;
	return (words);
}

char	ft_strlen(char *str, int i)
{
	while (str[i] != '\0' && separator(str[i]) < 0)
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

char	**ft_split_whitespaces(char *str)
{
	char	**array;
	int		i;
	int		n;

	i = 0;
	n = 0;
	array = (char **)malloc(sizeof(char*) * ft_strword(str) + 1);
	while (str[i] != '\0')
	{
		if (separator(str[i]) > 0)
			i++;
		else
		{
			array[n] = (char *)malloc(sizeof(**array) * ft_strlen(str, i));
			while (separator(str[i]) < 0 && str[i] != '\0')
			{
				ft_strcat(array[n], *(str + i));
				i++;
			}
			n++;
		}
	}
	array[n] = 0;
	return (array);
}
