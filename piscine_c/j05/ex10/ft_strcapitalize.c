/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 18:49:20 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 17:05:12 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		alpha(char s)
{
	if ((s > 47 && s < 58) || (s > 64 && s < 91) || (s > 96 && s < 123))
		return (1);
	else
		return (-1);
}

int		lower(char s)
{
	if (s > 64 && s < 91)
		s += 32;
	return (s);
}

int		upper(char s)
{
	if (s > 96 && s < 123)
		s -= 32;
	return (s);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i > 0)
		{
			if (alpha(str[i - 1]) < 0)
				str[i] = upper(str[i]);
			if (alpha(str[i - 1]) > 0)
				str[i] = lower(str[i]);
		}
		else
		{
			if (str[i] > 96 && str[i] < 123)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
