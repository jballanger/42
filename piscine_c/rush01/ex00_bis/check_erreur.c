/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erreur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:49:09 by jballang          #+#    #+#             */
/*   Updated: 2016/09/11 16:16:50 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);

int		check_erreur(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc != 10)
	{
		ft_putstr("Erreur\n");
		return (1);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] > '9' && argv[i][j] < '1')
			{
				ft_putstr("Erreur\n");
				return (1);
			}
			j++;
		}
		if (j > 9)
		{
			ft_putstr("Erreur\n");
			return (1);
		}
		i++;
	}
	return (0);
}
