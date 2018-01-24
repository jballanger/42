/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 16:21:42 by jballang          #+#    #+#             */
/*   Updated: 2016/09/01 15:02:21 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char	x;
	int		n;

	x = 'a';
	n = 0;
	while (n < 26)
	{
		ft_putchar(x + n);
		n++;
	}
}