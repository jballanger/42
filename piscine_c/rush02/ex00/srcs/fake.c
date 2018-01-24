/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 13:16:36 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 15:49:32 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		fake(char *str, char *name, int x, int y, int w)
{
	char	*colle00;
	char	*colle01;
	char	*colle02;
	char	*colle03;
	char	*colle04;

	w = 1;
	colle00 = "[colle-00]";
	colle01 = "[colle-01]";
	colle02 = "[colle-02]";
	colle03 = "[colle-03]";
	colle04 = "[colle-04]";
	if (name == colle00)
		w = fake00(str, x, y);
	else if (name == colle01)
		w = fake01(str, x, y);
	else if (name == colle02)
		w = fake02(str, x, y);
	else if (name == colle03)
		w = fake03(str, x, y);
	else if (name == colle04)
		w = fake04(str, x, y);
	return (w);
}
