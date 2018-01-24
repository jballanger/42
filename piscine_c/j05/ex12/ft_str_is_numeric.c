/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 20:13:47 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 11:05:20 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	num(char str)
{
	if (str > 47 && str < 58)
		return (1);
	else
		return (-1);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (num(str[i]) > 0 && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
