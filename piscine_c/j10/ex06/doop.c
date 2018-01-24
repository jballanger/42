/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 12:29:31 by jballang          #+#    #+#             */
/*   Updated: 2016/09/13 13:30:47 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		check_error(char **argv);
int		ft_atoi(char *str);
int		ft_add(int v1, int v2);
int		ft_minus(int v1, int v2);
int		ft_mult(int v1, int v2);
int		ft_mod(int v1, int v2);
int		ft_div(int v1, int v2);

int		ope(char operator)
{
	if (operator == '+')
		return (0);
	if (operator == '-')
		return (1);
	if (operator == '*')
		return (2);
	if (operator == '%')
		return (3);
	if (operator == '/')
		return (4);
	return (-1);
}

int		main(int argc, char **argv)
{
	int	(*operator[5])(int, int);

	operator[0] = ft_add;
	operator[1] = ft_minus;
	operator[2] = ft_mult;
	operator[3] = ft_mod;
	operator[4] = ft_div;
	if (argc != 4)
		return (0);
	if (check_error(argv) > 0)
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	if (ope(argv[2][0]) >= 0)
		(*operator[ope(argv[2][0])])(ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putchar('\n');
	return (0);
}
