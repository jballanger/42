/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 11:06:10 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 11:09:54 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	low(char str)
{
	if (str > 96 && str < 123)
		return (1);
	else
		return (-1);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (low(str[i]) > 0 && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
