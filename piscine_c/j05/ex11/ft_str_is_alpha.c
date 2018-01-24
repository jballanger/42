/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 19:33:54 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 11:00:18 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alphab(char str)
{
	if ((str > 64 && str < 91) || (str > 96 && str < 123))
		return (1);
	else
		return (-1);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (alphab(str[i]) > 0 && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
