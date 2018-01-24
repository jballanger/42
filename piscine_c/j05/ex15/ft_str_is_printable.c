/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 11:14:26 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 11:19:49 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	printable(char str)
{
	if (str > 31)
		return (1);
	else
		return (-1);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (printable(str[i]) > 0 && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
