/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 23:07:32 by jballang          #+#    #+#             */
/*   Updated: 2016/09/04 00:04:53 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb >= 0 && nb < 13)
	{
		if ((nb - 1) > 0)
		{
			return (nb *= ft_recursive_factorial(nb - 1));
		}
		else
		{
			return (1);
		}
	}
	else
	{
		return (0);
	}
}
