/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 08:36:25 by jballang          #+#    #+#             */
/*   Updated: 2016/11/30 13:23:00 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# ifndef FCNTL_H
#  define FCNTL_H
#  include <fcntl.h>
# endif

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# include "../libft/libft.h"
# define BUF_SIZE 4096

typedef struct		s_tetris
{
	int				*p1;
	int				*p2;
	int				*p3;
	int				*p4;
	struct s_tetris	*next;
	struct s_tetris	*prev;
}					t_tetris;

void				fillit(char *source);
void				logic(char *source);
char				*check(char *source);
int					position(char *source);
int					*pos_p1(char **super, int x, int y, int c);
int					*pos_p2(char **super, int x, int y, int c);
int					*pos_p3(char **super, int x, int y, int c);
int					*pos_p4(char **super, int x, int y, int c);
int					count_tetriminos(char *source);
t_tetris			*place_it(t_tetris *list);
char				**make_square(t_tetris *list);
char				**increase_size(char **square, size_t length);
char				**solve_it(char **square, t_tetris *list);
int					ft_rrange(t_tetris *list);

#endif
