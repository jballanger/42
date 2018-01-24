/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:46:02 by jballang          #+#    #+#             */
/*   Updated: 2016/09/08 23:07:15 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		c(int hour)
{
	if (hour > 12)
		return (hour - 12);
	else
		return (hour);
}

char	*a(int hour)
{
	if (hour < 12)
		return (".00 A");
	else
		return (".00 P");
}

void	ft_takes_place(int hour)
{
	char	*b;
	char	*z;
	char	*magie;
	int		h;

	if (hour >= 0 && hour < 24)
	{
		h = hour;
		b = "THE FOLLOWING TAKES PLACE BETWEEN ";
		z = ".M AND ";
		magie = "THE FOLLOWING TAKES PLACE BETWEEN ";
		if (hour == 12)
			printf("%s12.00 P.M AND 1.00 P.M.\n", magie);
		else if (hour == 0)
			printf("%s12.00 A.M AND 1.00 A.M.\n", magie);
		if (hour == 23)
			printf("%s11.00 P.M AND 12.00 A.M.\n", magie);
		else
			printf("%s%d%s%s%d%s.M.\n", b, c(h), a(h), z, c(h + 1), a(h + 1));
	}
}
