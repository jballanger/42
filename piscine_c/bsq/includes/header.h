/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 09:43:54 by jballang          #+#    #+#             */
/*   Updated: 2016/09/21 19:46:45 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		is_valid(char *buf);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		jesus_fill(char *buf, char infos[3]);
void	search(char infos[3], int **tab, int xmax, int ymax);
int		get_x(char *buf);
int		get_y(char *buf);

#endif
