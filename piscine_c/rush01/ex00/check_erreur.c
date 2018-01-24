/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erreur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:49:09 by jballang          #+#    #+#             */
/*   Updated: 2016/09/11 17:22:21 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

int		check_num(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] > '9' || argv[i][j] < '1') && argv[i][j] != '.')
				return (1);
			j++;
		}
		if (j > 9)
			return (1);
		i++;
	}
	return (0);
}

int		check_erreur(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc != 10)
	{
		ft_putstr("Erreur\n");
		return (1);
	}
	if (check_num(argv, i, j) > 0)
	{
		ft_putstr("Erreur\n");
		return (1);
	}
	return (0);
}
