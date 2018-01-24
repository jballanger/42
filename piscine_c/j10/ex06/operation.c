/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 17:56:17 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 13:29:47 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	ft_putnbr(int nb);

int		ft_add(int s1, int s2)
{
	ft_putnbr(s1 + s2);
	return (0);
}

int		ft_minus(int s1, int s2)
{
	ft_putnbr(s1 - s2);
	return (0);
}

int		ft_mult(int s1, int s2)
{
	ft_putnbr(s1 * s2);
	return (0);
}

int		ft_mod(int s1, int s2)
{
	if (s2 == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (0);
	}
	ft_putnbr(s1 % s2);
	return (0);
}

int		ft_div(int s1, int s2)
{
	if (s2 == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (0);
	}
	ft_putnbr(s1 / s2);
	return (0);
}
