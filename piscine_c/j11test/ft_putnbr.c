/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleroi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:17:48 by mleroi            #+#    #+#             */
/*   Updated: 2016/09/01 20:49:24 by mleroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int div;

	div = 1;
	if (nb < 0)
		ft_putchar('-');
	else
		nb = -nb;
	while ((nb / div) <= -10)
	{
		div = div * 10;
	}
	while (div >= 1)
	{
		ft_putchar(-(nb / div) + '0');
		nb = nb % div;
		div = div / 10;
	}
}
