/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 14:33:34 by jballang          #+#    #+#             */
/*   Updated: 2017/01/31 14:58:56 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strcat_one(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

int		isopt(char c)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' ||\
		c == 't' || c == 'f' || c == 'g')
		return (1);
	return (0);
}

int		is_validopt(char *opt)
{
	if (ft_strchr(opt, 'l') ||\
		ft_strchr(opt, 'R') ||\
		ft_strchr(opt, 'a') ||\
		ft_strchr(opt, 'r') ||\
		ft_strchr(opt, 't') ||\
		ft_strchr(opt, 'f') ||\
		ft_strchr(opt, 'g'))
		return (1);
	return (0);
}

char	*ft_parseargs(int i, char **argv, char *tmp_opt)
{
	int	j;

	j = 1;
	while (argv[i][j] != '\0')
	{
		if (!isopt(argv[i][j]))
			leave(argv[i][j]);
		if (tmp_opt)
			tmp_opt = ft_strcat_one(tmp_opt, argv[i][j]);
		else
			tmp_opt = ft_strcat_one("", argv[i][j]);
		j++;
	}
	return (tmp_opt);
}

void	ft_parser(int argc, char **argv, char **opt, t_list **directory)
{
	int		i;
	char	*tmp_opt;
	t_list	*tmp_dir;

	i = 1;
	if (!(tmp_opt = (char*)malloc(sizeof(char) * ft_strlen(argv[1] - 1))))
		malleave("parser.c:74");
	tmp_dir = NULL;
	while (i < argc && argv[i][0] == '-' && argv[i][1] && argv[i][1] != '-')
		tmp_opt = ft_parseargs(i++, argv, tmp_opt);
	if (argv[i] && ft_strcmp(argv[i], "--") == 0)
		i++;
	while (i < argc)
	{
		if (tmp_dir)
			ft_lstpush(&tmp_dir, ft_lstnew(argv[i], ft_strlen(argv[i])));
		else
			tmp_dir = ft_lstnew(argv[i], ft_strlen(argv[i]));
		i++;
	}
	(tmp_opt) ? (*opt = tmp_opt) : NULL;
	if (tmp_dir)
		*directory = tmp_dir;
	else
		*directory = ft_lstnew(".", 1);
}
