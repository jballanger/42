/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 15:50:38 by jballang          #+#    #+#             */
/*   Updated: 2016/09/18 16:25:15 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct		s_list
{
	struct s_list	*next;
	char			data;
}					t_list;
t_list				*ft_create_elem(char data);
void				colle00(char *str);
void				colle01(char *str);
void				colle234(char *str);
void				printer(char *str, int x, int y, int last);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr(char *str);
int					ft_strcmp(char *s1, char *s2);
int					fake(char *str, char *name, int x, int y, int w);
int					fake00(char *str, int x, int y);
int					fake01(char *str, int x, int y);
int					fake02(char *str, int x, int y);
int					fake03(char *str, int x, int y);
int					fake04(char *str, int x, int y);
char				*ft_strcat(char *dest, char src);
char				*create_real00(int x, int y);
char				*create_real01(int x, int y);
char				*create_real02(int x, int y);
char				*create_real03(int x, int y);
char				*create_real04(int x, int y);

#endif
