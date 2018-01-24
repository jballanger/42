/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 21:00:12 by jballang          #+#    #+#             */
/*   Updated: 2016/09/17 17:41:22 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int index;
	int sign;
	int nb;

	index = 0;
	nb = 0;
	sign = 0;
	while (str[index] == ' ' || str[index] == 9 || str[index] == 10 ||
			str[index] == 11 || str[index] == 12 || str[index] == 13)
		index++;
	if (str[index] == '-')
		sign = 1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		nb *= 10;
		nb += (str[index] - '0');
		index++;
	}
	if (sign == 1)
		return (-nb);
	else
		return (nb);
}
