/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:40:50 by jballang          #+#    #+#             */
/*   Updated: 2016/09/02 16:50:14 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while ((*(str + i)) != '\0')
	{
		i++;
	}
	i--;
	while (i > 0)
	{
		(*(str + i)) = (*(str + n));
		i--;
		n++;
	}
	return (str);
}
