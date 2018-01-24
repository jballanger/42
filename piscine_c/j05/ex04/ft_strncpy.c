/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 12:19:47 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 13:23:25 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n)
	{
		while (src[index] != '\0' && index < n)
		{
			dest[index] = src[index];
			index++;
		}
		if (index < n)
		{
			dest[index] = '\0';
			index++;
		}
		return (dest);
	}
	return (0);
}
