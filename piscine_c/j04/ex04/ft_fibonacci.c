/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:04:18 by jballang          #+#    #+#             */
/*   Updated: 2016/09/03 18:29:10 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	else
	{
		if(((ft_fibonacci(index - 1)) + (ft_fibonacci(index - 2))) <= 1)
		{
			return (index);
		}
		return (((ft_fibonacci(index - 1)) + (ft_fibonacci(index - 2))));
	}
}

int	main(void)
{
	printf("%d", ft_fibonacci(8));
	return (0);
}
