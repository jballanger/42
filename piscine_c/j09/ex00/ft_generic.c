/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:06:13 by jballang          #+#    #+#             */
/*   Updated: 2016/09/08 18:45:39 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (*(str + index) != '\0')
	{
		ft_putchar(*(str + index));
		index++;
	}
}

void	ft_generic(void)
{
	char	*generic;

	generic = "Tu tu tu tu ; Tu tu tu tu";
	ft_putstr(generic);
	ft_putchar('\n');
}
