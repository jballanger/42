/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 11:10:33 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 11:13:57 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	upper(char str)
{
	if (str > 64 && str < 91)
		return (1);
	else
		return (-1);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (upper(str[i]) > 0 && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
