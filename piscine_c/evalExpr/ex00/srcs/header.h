/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 08:43:26 by jballang          #+#    #+#             */
/*   Updated: 2016/09/17 10:37:52 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		eval_expr(char *expr);
int		calc(char *expr, int start, int end);
int		ft_atoi(char *str);

#endif
