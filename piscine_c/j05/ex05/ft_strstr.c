/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:46:07 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 22:27:03 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index;
	int	find_i;
	int	mark;

	index = 0;
	find_i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[index + 1] != '\0')
	{
		if (str[index] == to_find[0])
		{
			mark = index;
			while (str[index] == to_find[find_i])
			{
				index++;
				find_i++;
			}
			if (to_find[find_i] == '\0')
				return (str + mark);
		}
		find_i = 0;
		index++;
	}
	return (0);
}
