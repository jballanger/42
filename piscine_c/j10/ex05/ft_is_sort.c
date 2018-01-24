/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 12:23:54 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 20:50:41 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ASC(int *tab, int length, int (*f))
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i + 1 < length)
	{
		while (f(tab[i], tab[i + 1]) == 0)
			i++;
		if (f(tab[i], tab[i + 1]) > 0)
			size++;
		i++;
	}
	return (size);
}

int		DESC(int *tab, int length, int (*f))
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i + 1 < length)
	{
		while (f(tab[i], tab[i + 1]) == 0)
			i++;
		if (f(tab[i], tab[i + 1]) < 0)
			size++;
		i++;
	}
	return (size);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	s;

	i = 0;
	if(ASC(tab, length, &f()) > DESC(tab, length, &f()))
		s = 1;
	if (s == 1)
	{
		while (i + 1 < length)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}	
	else
	{
		while (i + 1 < length)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
			i++;
		}
	}
	return (1);
}
