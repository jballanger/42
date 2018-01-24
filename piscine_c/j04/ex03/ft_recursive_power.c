/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:50:44 by jballang          #+#    #+#             */
/*   Updated: 2016/09/03 23:48:30 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	if (power > 0)
	{
		return (ft_recursive_power(nb * nb, power - 1));
	}
	else
	{
		return (1);
	}
}

int	main(void)
{
	printf("%d", ft_recursive_power(3, 3));
	return (0);
}
