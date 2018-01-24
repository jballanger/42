/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:13:36 by jballang          #+#    #+#             */
/*   Updated: 2016/09/07 12:52:24 by jballang         ###   ########.fr       */
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
	if (argc > 1)
	{
		while (index < argc)
		{
			ft_putstr(argv[index]);
			ft_putchar('\n');
			index++;
		}
	}
	return (0);
}
