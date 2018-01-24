/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 09:38:16 by jballang          #+#    #+#             */
/*   Updated: 2016/09/06 12:39:58 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strncat(char *dest, char *src, int nb);

int	main(void)
{

	char str1[20];
	char str2[20];
	strcpy (str1,"To be ");
	strcpy (str2,"or not to be");
	ft_strncat (str1, str2, 6);
	puts (str1);
	return 0;}
