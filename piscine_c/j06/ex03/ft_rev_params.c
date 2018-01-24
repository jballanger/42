/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:24:59 by jballang          #+#    #+#             */
/*   Updated: 2016/09/07 12:54:55 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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

int		main(int argc, char **argv)
{
	int	index;

	index = 1;
	while (argc >= index + 1)
		index++;
	while (index > 1)
	{
		ft_putstr(argv[index - 1]);
		ft_putchar('\n');
		index--;
	}
	return (0);
}
