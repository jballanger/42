/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 21:24:55 by jballang          #+#    #+#             */
/*   Updated: 2016/09/01 23:16:04 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int	rev[9];
	int	i;

	i = 0;
	while (nb >= 1)
	{
		rev[i] = ((nb % 10) + 48);
		nb = (nb / 10);
		i++;
	}
	while (i >= 0)
	{
		ft_putchar(rev[i]);
		i--;
	}
}
