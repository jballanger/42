/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:53:02 by jballang          #+#    #+#             */
/*   Updated: 2017/03/09 10:12:44 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check(char **input)
{
	int		length;

	length = ft_length(input);
	if (length > 3)
		ft_putendl("setenv: Too many arguments.");
	else if (length < 2)
		display_env();
	else if (ft_strchr(input[1], '='))
		ft_putendl(\
			"setenv: Variable name must contain alphanumeric characters.");
	else
		return (1);
	return (0);
}

void	ft_setenv(char **input)
{
	extern char	**environ;
	char		**newenv;
	char		*tmp;

	if (check(input))
	{
		input[1] = ft_strcat(input[1], "=");
		if (input[2])
			tmp = ft_strjoin(input[1], input[2]);
		else
			tmp = ft_strdup(input[1]);
		newenv = env_add(environ, tmp);
		ft_arrdel(environ);
		free(tmp);
		environ = newenv;
	}
}
