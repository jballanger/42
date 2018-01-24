/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 18:24:54 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 13:26:04 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (s1[index] == s2[index] && index != n)
		index++;
	if (s1[index] > s2[index])
		return (1);
	if (s1[index] < s2[index])
		return (-1);
	if (s1[index] == s2[index])
		return (0);
	return (0);
}
