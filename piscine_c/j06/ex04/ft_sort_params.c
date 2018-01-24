/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:37:41 by jballang          #+#    #+#             */
/*   Updated: 2016/09/07 22:38:28 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
		index++;
	if (s1[index] == s2[index])
		return (0);
	else
		return (s1[index] - s2[index]);
}

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

void	printer(char **to_print)
{
	ft_putstr(*to_print);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int		index;
	int		swap;
	int		n;

	index = 2;
	swap = 1;
	n = 1;
	while (swap > 0)
	{
		swap = 0;
		while (argv[index])
		{
			if (ft_strcmp(argv[index - 1], argv[index]) > 0)
			{
				argv[0] = argv[index];
				argv[index] = argv[index - 1];
				argv[index - 1] = argv[0];
				swap = 1;
			}
			index++;
		}
		index = 2;
	}
	while (n++ < argc)
		printer(&argv[n - 1]);
}
