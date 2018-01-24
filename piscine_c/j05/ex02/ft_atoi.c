/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 10:12:32 by jballang          #+#    #+#             */
/*   Updated: 2016/09/07 11:02:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int	index;
	int nb;
	int	neg;

	index = 0;
	nb = 0;
	while (str[index] == '\f' || str[index] == '\n' || str[index] == '\r')
		index++;
	while (str[index] == '\t' || str[index] == '\v' || str[index] == ' ')
		index++;
	if (str[index] == '+' && str[index + 1] > 47 && str[index + 1] < 58)
		index++;
	if (str[index] == '-')
	{
		neg = index;
		index += 1;
	}
	while ((str[index] - 48 <= 9 && str[index] - 48 >= 0))
	{
		nb = (nb * 10) + str[index] - 48;
		index++;
	}
	if (str[neg] == '-')
		nb *= -1;
	return (nb);
}
